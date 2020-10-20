#ifndef MYGL_H
#define MYGL_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "math.h"
#include "core.h"

void InitMyGl(void);              // Inicializa o frame buffer
unsigned char *GetFBMemPtr(void); // Retorna o ponteiro do framebuffer buffer
void CloseMyGl(void);             // Desaloca a memória do framebuffer

// Declaração da função que chamará as funções implementadas pelo aluno
void MyGlDraw(void);
int CalculateDistance(int coordinateOne, int coordinateTwo);
void PutPixel(int coordinateX, int coordinateY, int RGBAColor[]);
void DrawLine(int CoordinateX0, int CoordinateY0, int CoordinateX1, int CoordinateY1, int ColorVertex0[], int ColorVertex1[]);
void DrawTriangle();

#endif // MYGL_H
