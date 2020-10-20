# Pratica I

## Compilando e Executando um Programa OpenGL Moderno

### Arthur Curty Vieira

##### Objetivos

O objetivo deste trabalho é a familiarização com os algoritmos de rasterização utilizados em computação gráfica.

#### O framework

##### Estrutura

<p align="justify">
Este framework simula o acesso direto à memória de vídeo. Os seus arquivos podem ser
acessados no <a href="https://github.com/capagot/icg/tree/master/02_mygl_framework">repositório disponibilizado pelo professor.
</a>

Abaixo segue a lista de arquivos que compõem este framework:

- core.h
- main.c
- main.h
- Makefile
- mygl.c
- mygl.h
</p>

<p align="justify">

Os arquivos main.h e main.c definem funções e variáveis necessárias a simulação de acesso à memória de vídeo. Este framework é acompanhado também de um script Makefile que serve como sugestão de procedimento de compilação para sistemas Unix. A compilação do framework é, de qualquer forma, responsabilidade do aluno.

Os arquivos mygl.h e mygl.c são os únicos arquivos que devem ser alterados durante a realização deste exercício. O arquivo mygl.h contém a declaração da função MyGlDraw(), responsável por invocar as funções de rasterização que os alunos irão desenvolver. É neste arquivo também os alunos deverão declarar as funções a serem desenvolvidas. O arquivo mygl.c é o lugar onde serão definidas as funções de rasterização. Este arquivo contém também a definição da função MyGlDraw(), cujo corpo o aluno deverá alterar de forma que suas funções de rasterização sejam devidamente invocadas.

</p>

##### Dependências

A compilação do projeto exige que os cabeçalhos do OpenGL e a GLUT (The OpenGL Toolkit) estejam instalados.Como especificado na descrição do projeto.
O ambiente está

### Desenvolvimento

<p align="justify">
O objetivo é desenvolver, ao menos, as três funções abaixo:
 
  - <b>PutPixel(...)</b>: Rasteriza um ponto na memória de vídeo recebendo como parâmetros as
  coordenadas (x,y) do pixel na tela e sua cor (RGBA).
  - <b>DrawLine(...)</b>: Rasteriza uma linha na tela, recebendo como parâmetros as coordenadas dos seus vértices inicial e final (representados respectivamente pelas tuplas (x0,y0) e (x1,y1)) e as cores (no formato RGBA) de cada vértice. As cores dos pixels ao longo da linha rasterizada devem ser obtidas por meio de interpolação linear das cores dos vértices. O algoritmo de rasterização de linha a ser implementado deve ser o Algoritmo do Ponto Médio!
  - <b>DrawTriangle(...)</b>: Função que desenha as arestas de um triângulo na tela, recebendo como parâmetros as posições dos três vértices (x0,y0), (x1,y1) e (x2,y2) bem como as cores (RGBA) de cada um dos vértices. As cores dos pixels das arestas do triângulo devem ser obtidas através da interpolação linear das cores de seus vértices. Não é necessário o preenchimento do triângulo!

Iniciando o desenvolvimento pela composição da função PutPixel(), que está apresenta abaixo:

</p>
<p align="center">
  <iframe
    src="https://carbon.now.sh/embed?bg=rgba(255%2C255%2C255%2C1)&t=seti&wt=none&l=text%2Fx-csrc&ds=false&dsyoff=20px&dsblur=68px&wc=true&wa=true&pv=6px&ph=21px&ln=false&fl=1&fm=Hack&fs=14px&lh=133%25&si=false&es=2x&wm=false&code=void%2520PutPixel(int%2520coordinateX%252C%2520int%2520coordinateY%252C%2520int%2520*RGBAColor)%250A%257B%250A%2520%2520%2520%2520for%2520(int%2520i%2520%253D%25200%253B%2520i%2520%253C%2520PIXEL_COMPONENTS%253B%2520i%252B%252B)%250A%2520%2520%2520%2520%257B%250A%2520%2520%2520%2520%2520%2520%2520%2520int%2520FB_COORDINATE%2520%253D%25204%2520*%2520coordinateY%2520*%2520IMAGE_WIDTH%2520%252B%25204%2520*%2520coordinateX%2520%252B%2520i%253B%250A%2520%2520%2520%2520%2520%2520%2520%2520fb_ptr%255BFB_COORDINATE%255D%2520%253D%2520RGBAColor%255Bi%255D%253B%250A%2520%2520%2520%2520%257D%250A%257D"
    style="width: 755px; height: 230px; border:0; transform: scale(1); overflow:hidden;"
    sandbox="allow-scripts allow-same-origin">
  </iframe>
</p>
<p align="justify">
Após a impementação, foi possivel testar chamando a função passando as coordenadas que devem ter as cores que foram passadas também como parâmetro.
</p>
<p align="center">
  <iframe
    src="https://carbon.now.sh/embed?bg=rgba(255%2C255%2C255%2C1)&t=seti&wt=none&l=text%2Fx-csrc&ds=false&dsyoff=20px&dsblur=68px&wc=true&wa=true&pv=6px&ph=21px&ln=false&fl=1&fm=Hack&fs=14px&lh=133%25&si=false&es=2x&wm=false&code=void%2520MyGlDraw(void)%250A%257B%250A%2520%2520%2520%2520int%2520RED_COLOR%255B4%255D%2520%253D%2520%257B255%252C%25200%252C%25200%252C%2520255%257D%253B%250A%2520%2520%2520%2520int%2520GREEN_COLOR%255B4%255D%2520%253D%2520%257B0%252C%2520255%252C%25200%252C%2520255%257D%253B%250A%2520%2520%2520%2520int%2520BLUE_COLOR%255B4%255D%2520%253D%2520%257B0%252C%25200%252C%2520255%252C%2520255%257D%253B%250A%250A%2520%2520%2520%2520PutPixel(106%252C%2520406%252C%2520RED_COLOR)%253B%250A%2520%2520%2520%2520PutPixel(105%252C%2520404%252C%2520GREEN_COLOR)%253B%250A%2520%2520%2520%2520PutPixel(104%252C%2520403%252C%2520BLUE_COLOR)%253B%250A%257D"
    style="width: 434px; height: 300px; border:0; transform: scale(1); overflow:hidden;"
    sandbox="allow-scripts allow-same-origin">
  </iframe>
</p>
<p align="justify">
Tendo como resultado a visualização abaixo:
</p>
<p align="center">
  <img src="./image/put-pixel.png" height="500"/>
</p>
<p align="justify">
O passo seguinte foi a crição da função DrawLine(), que foi criada recebendo os parâmetros abaixo, porem por ser a maior função, não vai ser apresentada como as anteriores.
</p>
<p align="center">
  <iframe
  src="https://carbon.now.sh/embed?bg=rgba(255%2C255%2C255%2C1)&t=seti&wt=none&l=text%2Fx-csrc&ds=false&dsyoff=20px&dsblur=68px&wc=true&wa=true&pv=6px&ph=21px&ln=false&fl=1&fm=Hack&fs=14px&lh=133%25&si=false&es=2x&wm=false&code=void%2520DrawLine(int%2520CoordinateX0%252C%2520int%2520CoordinateY0%252C%2520int%2520CoordinateX1%252C%2520%250A%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520int%2520CoordinateY1%252C%2520int%2520*ColorVertex0%252C%2520int%2520*ColorVertex1)%250A%257B%250A%2509%2509%2509%2509.%250A%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520.%250A%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520.%250A%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520.%250A%257D"
  style="width: 662px; height: 230px; border:0; transform: scale(1); overflow:hidden;"
  sandbox="allow-scripts allow-same-origin">
</iframe>
<p align="justify">
A função possui ainda uma chamada para a função abaixo, que é responsavel por retornar o valor da distancia entre dois vertices.
</p>
<p align="center">
  <iframe
    src="https://carbon.now.sh/embed?bg=rgba(255%2C255%2C255%2C1)&t=seti&wt=none&l=text%2Fx-csrc&ds=false&dsyoff=20px&dsblur=68px&wc=true&wa=true&pv=6px&ph=21px&ln=false&fl=1&fm=Hack&fs=14px&lh=133%25&si=false&es=2x&wm=false&code=int%2520CalculateDistance(int%2520coordinateOne%252C%2520int%2520coordinateTwo)%250A%257B%250A%2520%2520%2520%2520return%2520coordinateOne%2520-%2520coordinateTwo%253B%250A%257D"
    style="width: 577px; height: 200px; border:0; transform: scale(1); overflow:hidden;"
    sandbox="allow-scripts allow-same-origin">
  </iframe>
</p>

</p>
<p align="justify">
Pós implementação, chmando a função, considerando que o eixo Y contem 511px e o eixo X tambémconte 511px, a formação do triangulo foi estipulada para ser centralizada, sendo assim pelos calculos os vestices seriam nos pontos (106,106), (406,406), (256,406). Usando a função DrawLine(), passando os vertices mencionados e suas respectivas cores, como é apresentado a baixo:
</p>
<p align="center">
  <iframe
    src="https://carbon.now.sh/embed?bg=rgba(255%2C255%2C255%2C1)&t=seti&wt=none&l=text%2Fx-csrc&ds=false&dsyoff=20px&dsblur=68px&wc=true&wa=true&pv=6px&ph=21px&ln=false&fl=1&fm=Hack&fs=14px&lh=133%25&si=false&es=2x&wm=false&code=void%2520MyGlDraw(void)%250A%257B%250A%250A%2520%2520%2520%2520int%2520RED_COLOR%255B4%255D%2520%253D%2520%257B255%252C%25200%252C%25200%252C%2520255%257D%253B%250A%2520%2520%2520%2520int%2520GREEN_COLOR%255B4%255D%2520%253D%2520%257B0%252C%2520255%252C%25200%252C%2520255%257D%253B%250A%2520%2520%2520%2520int%2520BLUE_COLOR%255B4%255D%2520%253D%2520%257B0%252C%25200%252C%2520255%252C%2520255%257D%253B%250A%250A%2520%2520%2520%2520DrawLine(106%252C%2520106%252C%2520406%252C%2520106%252C%2520GREEN_COLOR%252C%2520BLUE_COLOR)%253B%250A%2520%2520%2520%2520DrawLine(406%252C%2520106%252C%2520256%252C%2520406%252C%2520BLUE_COLOR%252C%2520RED_COLOR)%253B%250A%2520%2520%2520%2520DrawLine(256%252C%2520406%252C%2520106%252C%2520106%252C%2520RED_COLOR%252C%2520GREEN_COLOR)%253B%250A%257D%250A"
    style="width: 569px; height: 320px; border:0; transform: scale(1); overflow:hidden;"
    sandbox="allow-scripts allow-same-origin">
  </iframe>
</p>
<p align="justify">
feito isso, as imagens abaixo representam a sequência de linhas que foram apresentas até a finalização do triangulo completo.
</p>
<p align="center">
  <img src="./image/base-triangulo.png" height="500"/>
</p>

<p align="center">
  <img src="./image/triangulo-com-lado-direito.png" height="500"/>
</p>

<p align="center">
  <img src="./image/triangulo-completo.png" height="500"/>
</p>

<p align="justify">
Finalizando assim o resultado esperado, mesmo que manualmente. Mas para que o objetivo seja alcançado ainda temos que implementar a função DrawTriangle(), que tem como intuito receber os 3 vertices, suas cores e criar no formato do triangulo como executado manualmente, alem de respeitar a regra definida de que as cores dos vertices devem ser iguais onde se encontram.
</p>

<p align="center">
  <iframe
    src="https://carbon.now.sh/embed?bg=rgba(255%2C255%2C255%2C1)&t=seti&wt=none&l=text%2Fx-csrc&ds=false&dsyoff=20px&dsblur=68px&wc=true&wa=true&pv=6px&ph=21px&ln=false&fl=1&fm=Hack&fs=14px&lh=133%25&si=false&es=2x&wm=false&code=void%2520DrawTriangle(int%2520CoordinateX0%252C%2520int%2520CoordinateY0%252C%2520int%2520CoordinateX1%252C%2520%250A%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520int%2520CoordinateY1%252C%2520int%2520CoordinateX2%252C%2520int%2520CoordinateY2%252C%2520%250A%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520%2520int%2520*ColorVertex0%252C%2520int%2520*ColorVertex1%252C%2520int%2520*ColorVertex2)%250A%257B%250A%2520%2520%2520%2520DrawLine(CoordinateX0%252C%2520CoordinateY0%252C%2520CoordinateX1%252C%2520CoordinateY1%252C%2520ColorVertex0%252C%2520ColorVertex1)%253B%250A%2520%2520%2520%2520DrawLine(CoordinateX1%252C%2520CoordinateY1%252C%2520CoordinateX2%252C%2520CoordinateY2%252C%2520ColorVertex1%252C%2520ColorVertex2)%253B%250A%2520%2520%2520%2520DrawLine(CoordinateX2%252C%2520CoordinateY2%252C%2520CoordinateX0%252C%2520CoordinateY0%252C%2520ColorVertex2%252C%2520ColorVertex0)%253B%250A%257D"
    style="width: 898px; height: 230px; border:0; transform: scale(1); overflow:hidden;"
    sandbox="allow-scripts allow-same-origin">
  </iframe>
</p>

Feito isso, ao executar o comando abaixo:

<p align="center">
  <iframe
    src="https://carbon.now.sh/embed?bg=rgba(255%2C255%2C255%2C1)&t=seti&wt=none&l=application%2Fx-sh&ds=false&dsyoff=20px&dsblur=68px&wc=true&wa=true&pv=6px&ph=21px&ln=false&fl=1&fm=Hack&fs=14px&lh=133%25&si=false&es=2x&wm=false&code=make%2520%2526%2526%2520.%252Fmygl"
    style="width: 200px; height: 120px; border:0; transform: scale(1); overflow:hidden;"
    sandbox="allow-scripts allow-same-origin">
  </iframe>
</p>

<p align="justify">
Assim o arquivo executavel <b>mygl</b> é gerado e executado em sequência, apresentado ao fim o resultado final esperado, que é o triângulo completo.
</p>

<p align="center">
  <img src="./image/triangulo-completo.png" height="500"/>
</p>

##### Probleas encontrados

<p align="justify">
Durante a execução do programa, alguns erros foram encontrados que não permitiam a geração do executavel, a solução foi a inclusão no arquivo MakeFile, da flag -lm. Tendo como resultado final o seguinde formato de arquivo:
</p>

<p align="center">
  <iframe
    src="https://carbon.now.sh/embed?bg=rgba(255%2C255%2C255%2C1)&t=seti&wt=none&l=application%2Fx-sh&ds=false&dsyoff=20px&dsblur=68px&wc=true&wa=true&pv=6px&ph=21px&ln=false&fl=1&fm=Hack&fs=14px&lh=133%25&si=false&es=2x&wm=false&code=CC%2520%253D%2520gcc%250A%250Aall%253A%250A%2509%2524(CC)%2520-Wall%2520-Wextra%2520-Wpedantic%2520-std%253Dc99%2520-O0%2520mygl.c%2520main.c%2520-lglut%2520-lGLU%2520-lGL%2520-o%2520mygl%2520-lm%250A%250Aclean%253A%250A%2509rm%2520mygl"
    style="width: 1024px; height: 250px; border:0; transform: scale(1); overflow:hidden;"
    sandbox="allow-scripts allow-same-origin">
  </iframe>
</p>

#### Referências

https://pt.wikipedia.org/wiki/Rasteriza%C3%A7%C3%A3o
https://askubuntu.com/questions/527665/undefined-reference-to-symbol-expglibc-2-2-5
http://disciplinas.ist.utl.pt/leic-cg/textos/livro/Rasterizacao.pdf
http://letslearnbits.blogspot.com/2014/10/icgt1-algoritmo-de-bresenham.html
https://letslearnbits.blogspot.com/2014/10/icgt1-interpolacao-de-cores.html
