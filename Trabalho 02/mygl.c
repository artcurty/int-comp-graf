#include "mygl.h"

unsigned char *fb_ptr = NULL;

int PIXEL_COMPONENTS = 4;

void InitMyGl(void)
{
    fb_ptr = (unsigned char *)malloc(IMAGE_WIDTH * IMAGE_HEIGHT * 4 * sizeof(char));

    for (int i = 0; i < IMAGE_WIDTH * IMAGE_HEIGHT; ++i)
    {
        fb_ptr[i * 4] = 0;
        fb_ptr[i * 4 + 1] = 0;
        fb_ptr[i * 4 + 2] = 0;
        fb_ptr[i * 4 + 3] = 255;
    }
}

unsigned char *GetFBMemPtr(void)
{
    return fb_ptr;
}

void CloseMyGl(void)
{
    if (!fb_ptr)
        free(fb_ptr);
}

void PutPixel(int coordinateX, int coordinateY, int *RGBAColor)
{

    for (int i = 0; i < PIXEL_COMPONENTS; i++)
    {
        int FB_COORDINATE = 4 * coordinateY * IMAGE_WIDTH + 4 * coordinateX + i;
        fb_ptr[FB_COORDINATE] = RGBAColor[i];
    }
}

int CalculateDistance(int coordinateOne, int coordinateTwo)
{
    return coordinateOne - coordinateTwo;
}

void DrawLine(int CoordinateX0, int CoordinateY0, int CoordinateX1, int CoordinateY1, int *ColorVertex0, int *ColorVertex1)
{

    int pY, pX, p, path;

    float R = ColorVertex0[0];
    float G = ColorVertex0[1];
    float B = ColorVertex0[2];
    float A = ColorVertex0[3];

    int x = CoordinateX0;
    int y = CoordinateY0;

    int distanceX = CalculateDistance(CoordinateX1, CoordinateX0);
    int distanceY = CalculateDistance(CoordinateY1, CoordinateY0);

    if (distanceX < 0)
    {
        pX = -1;
    }
    else
    {
        pX = 1;
    }

    if (distanceY < 0)
    {
        pY = -1;
    }
    else
    {
        pY = 1;
    }

    distanceX = abs(distanceX);
    distanceY = abs(distanceY);

    float totalDistance = sqrt(pow(distanceX, 2) + pow(distanceY, 2));

    float compareValueRed = (ColorVertex1[0] - ColorVertex0[0]) / totalDistance;
    float compareValueGreen = (ColorVertex1[1] - ColorVertex0[1]) / totalDistance;
    float compareValueBlue = (ColorVertex1[2] - ColorVertex0[2]) / totalDistance;
    float compareValueAlpha = (ColorVertex1[3] - ColorVertex0[3]) / totalDistance;

    if (distanceX > distanceY)
    {
        path = distanceX;
    }
    else
    {
        path = distanceY;
    }

    p = path / 2;

    PutPixel(x, y, ColorVertex0);

    while (path > 0)
    {
        if (distanceX > distanceY)
        {
            x += pX;
            p += distanceY;

            if (p >= distanceX)
            {
                y += pY;
                p -= distanceX;
            }
        }
        else
        {
            y += pY;
            p += distanceX;

            if (p >= distanceY)
            {
                x += pX;
                p -= distanceY;
            }
        }

        R += compareValueRed;
        G += compareValueGreen;
        B += compareValueBlue;
        A += compareValueAlpha;

        int RGBA[4] = {R, G, B, A};

        PutPixel(x, y, RGBA);
        path--;
    }

    PutPixel(x, y, ColorVertex1);
}

void DrawTriangle(int CoordinateX0, int CoordinateY0, int CoordinateX1, int CoordinateY1, int CoordinateX2, int CoordinateY2, int *ColorVertex0, int *ColorVertex1, int *ColorVertex2)
{
    DrawLine(CoordinateX0, CoordinateY0, CoordinateX1, CoordinateY1, ColorVertex0, ColorVertex1);
    DrawLine(CoordinateX1, CoordinateY1, CoordinateX2, CoordinateY2, ColorVertex1, ColorVertex2);
    DrawLine(CoordinateX2, CoordinateY2, CoordinateX0, CoordinateY0, ColorVertex2, ColorVertex0);
}

// Definição da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void)
{

    int RED_COLOR[4] = {255, 0, 0, 255};
    int GREEN_COLOR[4] = {0, 255, 0, 255};
    int BLUE_COLOR[4] = {0, 0, 255, 255};

    DrawTriangle(106, 106, 406, 106, 256, 406, RED_COLOR, GREEN_COLOR, BLUE_COLOR);
}