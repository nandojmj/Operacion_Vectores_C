/*Hacer un modulo que realice:
* Suma de componentes Vectoriales, Magnitud y Direccion
* Producto Vectorial, Magnitud y Direccion
* Producto Punto, Magnitud y Direccion

* Suma de Vectores Unitarios*/

#include <math.h>     //matematico
#include <conio.h>    //limpia
#include <stdio.h>    //getchar espera una tecla
#include <iostream.h> //cin y cout
#include <graphics.h> //unidad grafica trabaja en pixeles
#include <stdlib.h>   //exit sale del programa sin finalizar todo
#include <string.h>   //strcpy inicializar las cadenas en vacio
void Pantalla ();//Dibuja la pantalla en donde se capturan todos los datos
void SumaVectorUnitario ();//Realiza la suma de vectores por sus componentes unitarios (Coordenada)
void SumaVectorRectangular ();//Realiza la suma de vectores por sus componentes rectangulares (Magnitud y Direccion)
void ProductoEscalar ();// Realiza el producto escalar
void ProductoVectorial ();//Realiza el producto vectorial
void MisionVision ();//Muestra la pantalla de Mision, Vision, Perfil Ocupacional Y Academico
void Menu ();//Muestra la pantalla del Menu
//**************************************************************************//
void main ()
{
   Menu ();
}
//**************************************************************************//
void Pantalla ()
{
   cleardevice ();//limpiar pantalla unidad grafica
   setlinestyle(1, 0, 3);//define el estilo de la linea
   rectangle (2, 2, getmaxx ()-2, getmaxy ()-2);//dibuja un rectangulo
   setlinestyle(2, 0, 2);
   rectangle (5,5,getmaxx ()-5, getmaxy ()-5);
   setlinestyle(1, 0, 3);
   rectangle (8,8,getmaxx ()-8, getmaxy ()-8);
   setbkcolor (MAGENTA);//define el color de fondo
   settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);//define el tama¤o, tipo de letra y orientacion del texto
   settextjustify (CENTER_TEXT, CENTER_TEXT);//justifica el texto
   outtextxy (getmaxx ()/2, 30, "Fundacion Universitaria San Martin");//imprime el texto en la coordenada especificada
   outtextxy (getmaxx ()/2, 60, "Ingenieria de Sistemas");
   outtextxy (getmaxx ()/2, 90, "Fisica 1");
   settextjustify (LEFT_TEXT, CENTER_TEXT);//justifica el texto
   rectangle (98,138,getmaxx ()-98, getmaxy ()-48);//Realiza Rectangulo Central
   rectangle (100,140,getmaxx ()-100, getmaxy ()-50);
   rectangle (102,142,getmaxx ()-102, getmaxy ()-52);
   setfillstyle(HATCH_FILL, LIGHTBLUE);//Define el estilo de relleno
   floodfill(108, 215, getcolor ());//Rellena desde la coordenada especificada hasta el color definido
   //GetColor trae el color de linea actual
}
//**************************************************************************//
void SumaVectorUnitario ()//Realiza la suma de vectores por sus componentes unitarios (Coordenada)
{
   char Caracter;
   char Cadena[250] = " ";
   float *ComponentesX;//Puntero para crear el vector
   float *ComponentesY;
   float ResultadoComponenteX,//Almacenan calculos y resultados
	 ResultadoComponenteY,
	 Magnitud,
	 Direccion;
   int i, j, TamVector, Desplazar, Modo;//Variables
   Pantalla ();//Dibuja la pantalla en donde se capturan todos los datos
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
   settextjustify (CENTER_TEXT, CENTER_TEXT);
   //Pide el numero de vectores con el que desea trabajar lo guarda en una
   //cadena y luego lo convierte a entero para poder hacer las operaciones
   //con los vectores.
   outtextxy (getmaxx () / 2, 240, "Digite el numero de vectores");
   j = 0;//Desplazarce por las posiciones de la cadena
   do
   {
      do
      {
	 Caracter = getche ();
      } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9'));
      Cadena[j] = Caracter;
      Cadena[j+1] = '\r';
      settextjustify (LEFT_TEXT, CENTER_TEXT);
      outtextxy (280, 280, Cadena);
      j++;
   } while (Caracter != '\r');
   Cadena[j] = '\r';
   TamVector = atoi(Cadena);//Convierte la cadena en un entero
   ComponentesX = new float[TamVector];//Se crea el vector del tama¤o especificado
   ComponentesY = new float[TamVector];
   for (i=0; i< TamVector; i++)//Recorre los vectores y los inicializa en cero
   {
      ComponentesX[i] = 0;
      ComponentesY[i] = 0;
   };
   for (i = 0; i < TamVector; i++)//Ciclo para llenar las coordenas de los vectores
   {
      Pantalla ();
      j = 0;
      do
      {
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	 outtextxy (120, 240, "Componente X: ");
	 do
	 {
	    Caracter = getche ();
	 } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9') && (Caracter != '.') && (Caracter != '-'));
	 Cadena[j] = Caracter;
	 Cadena[j+1] = '\r';
	 Desplazar = textwidth("Componente X: ");
	 outtextxy (120+Desplazar, 240, Cadena);
	 j++;
      } while (Caracter != '\r');
      Cadena[j] = '\r';
      ComponentesX[i] = atof(Cadena);//convierte la cadena en float
      strcpy(Cadena, "                                                       ");//Copia una texto en la cadena
      j = 0;
      do
      {
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	 outtextxy (120, 320, "Componente Y: ");
	 do
	 {
	    Caracter = getche ();
	 } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9') && (Caracter != '.') && (Caracter != '-'));
	 Cadena[j] = Caracter;
	 Cadena[j+1] = '\r';
	 Desplazar = textwidth("Componente X: ");
	 outtextxy (120+Desplazar, 320, Cadena);
	 j++;
      } while (Caracter != '\r');
      Cadena[j] = '\r';
      ComponentesY[i] = atof(Cadena);
      strcpy(Cadena, "                                                       ");
   }
   //Operaciones para la suma de vectores unitarios
   ResultadoComponenteX = 0;
   ResultadoComponenteY = 0;
   for(i = 0; i < TamVector; i++)//Suma las componentes
   {
      ResultadoComponenteX = ResultadoComponenteX + ComponentesX[i];
      ResultadoComponenteY = ResultadoComponenteY + ComponentesY[i];
   }
   Magnitud = sqrt(pow(ResultadoComponenteX, 2) + pow(ResultadoComponenteY, 2));
   Direccion = atan(ResultadoComponenteY/ResultadoComponenteX);//Resultado en radianes
   Direccion = (Direccion * 180)/3.1416;//Convertimos a grados
   Modo = getgraphmode();//Guardar el modo grafico actual
   restorecrtmode();//Restaura el modo CRT, Se pasa a CRT (Columnas y filas) sin cerrar la unidad grafica
   clrscr ();
   cout << "Componente X vector resultante:" << ResultadoComponenteX << endl;
   cout << "Componente Y vector resultante:" << ResultadoComponenteY << endl;
   cout << "Magnitud vector resultante:" << Magnitud << endl;
   cout << "Direccion vector resultante:" << Direccion << endl;
   getch ();
   Modo = getgraphmode();
   setgraphmode(Modo);//Restaura el Modo Grafico
}
//**************************************************************************//
void SumaVectorRectangular () //Realiza la suma de vectores por sus componentes rectangulares (Magnitud y Direccion)
{                             //halla las componentes unitarias del vector y realiza la suma por componentes unitarios.
   char Caracter;
   char Cadena[250] = " ";
   float *VectorMagnitud;
   float *VectorDireccion;
   float ResultadoComponenteX,
	 ResultadoComponenteY,
	 Magnitud,
	 Direccion;
   int i, j, TamVector, Desplazar, Modo;
   Pantalla ();
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
   settextjustify (CENTER_TEXT, CENTER_TEXT);
   outtextxy (getmaxx ()/2, 240, "Digite el numero de vectores");
   j = 0;
   do
   {
      do
      {
	 Caracter = getche ();
      } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9'));
      Cadena[j] = Caracter;
      Cadena[j+1] = '\r';
      settextjustify (LEFT_TEXT, CENTER_TEXT);
      outtextxy (280, 280, Cadena);
      j++;
   } while (Caracter != '\r');
   Cadena[j] = '\r';
   TamVector = atoi(Cadena);
   VectorMagnitud = new float[TamVector];
   VectorDireccion = new float[TamVector];

   for (i=0; i< TamVector; i++)
   {
      VectorMagnitud[i] = 0;
      VectorDireccion[i] = 0;
   };

   for (i = 0; i < TamVector; i++)
   {
      Pantalla ();
      j = 0;
      do
      {
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	 outtextxy (120, 240, "Magnitud: ");
	 do
	 {
	    Caracter = getche ();
	 } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9') && (Caracter != '.') && (Caracter != '-'));
	 Cadena[j] = Caracter;
	 Cadena[j+1] = '\r';
	 Desplazar = textwidth("Magnitud: ");
	 outtextxy (120+Desplazar, 240, Cadena);
	 j++;
      } while (Caracter != '\r');
      Cadena[j] = '\r';
      VectorMagnitud[i] = atof(Cadena);
      strcpy(Cadena, "                                                       ");
      j = 0;
      do
      {
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	 outtextxy (120, 320, "Direccion: ");
	 do
	 {
	    Caracter = getche ();
	 } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9') && (Caracter != '.') && (Caracter != '-'));
	 Cadena[j] = Caracter;
	 Cadena[j+1] = '\r';
	 Desplazar = textwidth("Direccion: ");
	 outtextxy (120+Desplazar, 320, Cadena);
	 j++;
      } while (Caracter != '\r');
      Cadena[j] = '\r';
      VectorDireccion[i] = atof(Cadena);
      strcpy(Cadena, "                                                       ");
   }
   ResultadoComponenteX = 0;
   ResultadoComponenteY = 0;
   for(i = 0; i < TamVector; i++)//halla las componentes unitaria y las suma
   {
      ResultadoComponenteX = ResultadoComponenteX + (VectorMagnitud[i] * (cos (VectorDireccion[i])));
      ResultadoComponenteY = ResultadoComponenteY + (VectorMagnitud[i] * (sin (VectorDireccion[i])));
   }
   Magnitud = sqrt(pow(ResultadoComponenteX, 2) + pow(ResultadoComponenteY, 2));
   Direccion = atan(ResultadoComponenteY/ResultadoComponenteX);
   Direccion = (Direccion * 180)/3.1416;
   Modo = getgraphmode();
   restorecrtmode();
   clrscr ();
   cout << "Componente X vector resultante:" << ResultadoComponenteX << endl;
   cout << "Componente Y vector resultante:" << ResultadoComponenteY << endl;
   cout << "Magnitud vector resultante:" << Magnitud << endl;
   cout << "Direccion vector resultante:" << Direccion << endl;
   getch ();
   Modo = getgraphmode();
   setgraphmode(Modo);
}
//**************************************************************************//
void ProductoEscalar ()
{
   char Caracter;
   char Cadena[250] = " ";
   float *ComponentesX;
   float *ComponentesY;
   float *ComponentesZ;
   float ResultadoComponenteX,
	 ResultadoComponenteY,
	 ResultadoComponenteZ,
	 Producto,
	 Magnitud,
	 Operacion,
	 Direccion;
   int i, j, TamVector, Desplazar, Modo;
   Pantalla ();
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
   settextjustify (CENTER_TEXT, CENTER_TEXT);
   outtextxy (getmaxx ()/2, 240, "Digite el numero de vectores");
   j = 0;
   do
   {
      do
      {
	 Caracter = getche ();
      } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9'));
      Cadena[j] = Caracter;
      Cadena[j+1] = '\r';
      settextjustify (LEFT_TEXT, CENTER_TEXT);
      outtextxy (280, 280, Cadena);
      j++;
   } while (Caracter != '\r');
   Cadena[j] = '\r';
   TamVector = atoi(Cadena);
   ComponentesX = new float[TamVector];
   ComponentesY = new float[TamVector];
   ComponentesZ = new float[TamVector];
   for (i=0; i< TamVector; i++)
   {
      ComponentesX[i] = 0;
      ComponentesY[i] = 0;
      ComponentesZ[i] = 0;
   };

   for (i = 0; i < TamVector; i++)
   {
      Pantalla ();
      j = 0;
      do
      {
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	 outtextxy (120, 200, "Componente X: ");
	 do
	 {
	    Caracter = getche ();
	 } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9') && (Caracter != '.') && (Caracter != '-'));
	 Cadena[j] = Caracter;
	 Cadena[j+1] = '\r';
	 Desplazar = textwidth("Componente X: ");
	 outtextxy (120+Desplazar, 200, Cadena);
	 j++;
      } while (Caracter != '\r');
      Cadena[j] = '\r';
      ComponentesX[i] = atof(Cadena);
      strcpy(Cadena, "                                                       ");
      j = 0;
      do
      {
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	 outtextxy (120, 280, "Componente Y: ");
	 do
	 {
	    Caracter = getche ();
	 } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9') && (Caracter != '.') && (Caracter != '-'));
	 Cadena[j] = Caracter;
	 Cadena[j+1] = '\r';
	 Desplazar = textwidth("Componente Y: ");
	 outtextxy (120+Desplazar, 280, Cadena);
	 j++;
      } while (Caracter != '\r');
      Cadena[j] = '\r';
      ComponentesY[i] = atof(Cadena);
      strcpy(Cadena, "                                                       ");

      j = 0;
      do
      {
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	 outtextxy (120, 360, "Componente Z: ");
	 do
	 {
	    Caracter = getche ();
	 } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9') && (Caracter != '.') && (Caracter != '-'));
	 Cadena[j] = Caracter;
	 Cadena[j+1] = '\r';
	 Desplazar = textwidth("Componente Z: ");
	 outtextxy (120+Desplazar, 360, Cadena);
	 j++;
      } while (Caracter != '\r');
      Cadena[j] = '\r';
      ComponentesZ[i] = atof(Cadena);
      strcpy(Cadena, "                                                       ");
   }
   ResultadoComponenteX = 1; //se inicializa en 1 para multiplicar
   ResultadoComponenteY = 1;
   ResultadoComponenteZ = 1;
   Magnitud = 1;
   for(i = 0; i < TamVector; i++)//acumula las multiplicasiones de las componentes
   {
      ResultadoComponenteX = ResultadoComponenteX * ComponentesX[i];//i
      ResultadoComponenteY = ResultadoComponenteY * ComponentesY[i];//j
      ResultadoComponenteZ = ResultadoComponenteZ * ComponentesZ[i]; //k
      Operacion = (sqrt( pow(ComponentesX[i], 2) + pow(ComponentesY[i], 2) + pow(ComponentesZ[i], 2))); //se halla la magnitud de cada vector
      Magnitud = Magnitud * Operacion; //se acumula el producto de las magnitudes
   }
   Direccion = acos((ResultadoComponenteY+ResultadoComponenteX+ResultadoComponenteZ)/(Magnitud));
   Direccion = (Direccion * 180)/3.1416;
   Modo = getgraphmode();
   restorecrtmode();
   clrscr ();
   cout << "Producto Escalar: " << ResultadoComponenteY+ResultadoComponenteX+ResultadoComponenteZ << endl;//da el resultado de el producto escalar
   cout << "Direccion: " << Direccion << endl;
   getch ();
   Modo = getgraphmode();
   setgraphmode(Modo);
}
//**************************************************************************//
void ProductoVectorial ()
{
   const TamVector = 2;
   char Caracter;
   char Cadena[250] = " ";
   float *ComponentesX;
   float *ComponentesY;
   float *ComponentesZ;
   float ResultadoComponenteX,
	 ResultadoComponenteY,
	 ResultadoComponenteZ,
	 Producto,
	 DResultadoComponenteX,
	 DResultadoComponenteY,
	 DResultadoComponenteZ,
	 DProducto,
	 DMagnitud,
	 DOperacion,
	 Direccion;
   int i, j, Desplazar, Modo;
   Pantalla ();
   settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
   settextjustify (CENTER_TEXT, CENTER_TEXT);
   ComponentesX = new float[TamVector];
   ComponentesY = new float[TamVector];
   ComponentesZ = new float[TamVector];
   for (i=0; i< TamVector; i++)
   {
      ComponentesX[i] = 0;
      ComponentesY[i] = 0;
      ComponentesZ[i] = 0;
   };
   for (i = 0; i < TamVector; i++)
   {
      Pantalla ();
      j = 0;
      do
      {
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	 outtextxy (120, 200, "Componente X: ");
	 do
	 {
	    Caracter = getche ();
	 } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9') && (Caracter != '.') && (Caracter != '-'));
	 Cadena[j] = Caracter;
	 Cadena[j+1] = '\r';
	 Desplazar = textwidth("Componente X: ");
	 outtextxy (120+Desplazar, 200, Cadena);
	 j++;
      } while (Caracter != '\r');
      Cadena[j] = '\r';
      ComponentesX[i] = atof(Cadena);
      strcpy(Cadena, "                                                       ");
      j = 0;
      do
      {
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	 outtextxy (120, 300, "Componente Y: ");
	 do
	 {
	    Caracter = getche ();
	 } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9') && (Caracter != '.') && (Caracter != '-'));
	 Cadena[j] = Caracter;
	 Cadena[j+1] = '\r';
	 Desplazar = textwidth("Componente Y: ");
	 outtextxy (120+Desplazar, 300, Cadena);
	 j++;
      } while (Caracter != '\r');
      Cadena[j] = '\r';
      ComponentesY[i] = atof(Cadena);
      strcpy(Cadena, "                                                       ");
      j = 0;
      do
      {
	 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	 outtextxy (120, 400, "Componente Z: ");
	 do
	 {
	    Caracter = getche ();
	 } while ((Caracter != '\r') && (Caracter != '0') && (Caracter != '1') && (Caracter != '2') && (Caracter != '3') && (Caracter != '4') && (Caracter != '5') && (Caracter != '6') && (Caracter != '7') && (Caracter != '8') && (Caracter != '9') && (Caracter != '.') && (Caracter != '-'));
	 Cadena[j] = Caracter;
	 Cadena[j+1] = '\r';
	 Desplazar = textwidth("Componente Z: ");
	 outtextxy (120+Desplazar, 400, Cadena);
	 j++;
      } while (Caracter != '\r');
      Cadena[j] = '\r';
      ComponentesZ[i] = atof(Cadena);
      strcpy(Cadena, "                                                       ");
   }
   ResultadoComponenteX = 1;
   ResultadoComponenteY = 1;
   ResultadoComponenteZ = 1;
   ResultadoComponenteX = ((ComponentesY[0] * ComponentesZ[1])-(ComponentesY[1] * ComponentesZ[0]));//hallamos el producto cruz de i
   ResultadoComponenteY = ((ComponentesX[0] * ComponentesZ[1])-(ComponentesX[1] * ComponentesZ[0]));//hallamos el producto cruz de j
   ResultadoComponenteZ = ((ComponentesX[0] * ComponentesY[1])-(ComponentesX[1] * ComponentesY[0]));//hallamos el producto cruz de k
   Producto = ResultadoComponenteX - ResultadoComponenteY + ResultadoComponenteZ;//resultado del pruducto cruz
   DResultadoComponenteX = 1;
   DResultadoComponenteY = 1;
   DResultadoComponenteZ = 1;
   DMagnitud = 1;
   for(i = 0; i < TamVector; i++)
   {
      DResultadoComponenteX = DResultadoComponenteX * ComponentesX[i];
      DResultadoComponenteY = DResultadoComponenteY * ComponentesY[i];
      DResultadoComponenteZ = DResultadoComponenteZ * ComponentesZ[i];
      DOperacion = (sqrt( pow(ComponentesX[i], 2) + pow(ComponentesY[i], 2) + pow(ComponentesZ[i], 2)));
      DMagnitud = DMagnitud * DOperacion;
   }
   Direccion = acos((DResultadoComponenteY+DResultadoComponenteX+DResultadoComponenteZ)/(DMagnitud));
   Direccion = (Direccion * 180)/3.1416;
   Modo = getgraphmode();
   restorecrtmode();
   clrscr ();
   cout << "Producto Vectorial: " << Producto << endl;
   cout << "Direccion: " << Direccion << endl;
   getch ();
   Modo = getgraphmode();
   setgraphmode(Modo);
}
//**************************************************************************//
void MisionVision ()
{
      cleardevice ();//limpiar pantalla unidad grafica
      setlinestyle(1, 0, 3);//define el estilo de la linea
      rectangle (2,2,getmaxx ()-2, getmaxy ()-2);//dibuja un rectangulo
      setlinestyle(2, 0, 2);
      rectangle (5,5,getmaxx ()-5, getmaxy ()-5);
      setlinestyle(1, 0, 3);
      rectangle (8,8,getmaxx ()-8, getmaxy ()-8);
      setbkcolor (MAGENTA);//define el color de fondo
      settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);//define el tama¤o tipo y orientacion del texto
      settextjustify (CENTER_TEXT, CENTER_TEXT);//justifica el texto
      outtextxy (getmaxx ()/2, 30, "Fundacion Universitaria San Martin");//imprime el texto en la coordenada especificada
      outtextxy (getmaxx ()/2, 60, "Ingenieria de Sistemas");
      outtextxy (getmaxx ()/2, 90, "Fisica 1");
      settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
      outtextxy (getmaxx ()/2, 150, "Mision, Vision, Perfil Ocupacional Y Academico");
      rectangle (38,188,getmaxx ()-38, getmaxy ()-48);
      rectangle (40,190,getmaxx ()-40, getmaxy ()-50);
      rectangle (42,192,getmaxx ()-42, getmaxy ()-52);
      setfillstyle(SOLID_FILL, 9);
      floodfill(108, 215, getcolor ());
      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
      settextjustify (LEFT_TEXT, CENTER_TEXT);//justifica el texto
      outtextxy (50, 210, "MISION: Los ingenieros seremos capaces de tener");
      outtextxy (50, 230, "h bilidades en la soluci¢n de problemas.");
      outtextxy (50, 260, "VISION: Seremos profesionales h biles.");
      outtextxy (50, 290, "OBJETIVO: Crear ingenieros id¢neos en el campo de");
      outtextxy (50, 320, "PERFIL OCUPACIONAL: Los ingeniros ser n capaces de");
      outtextxy (50, 340, "laboral en cualquier campo de la inform tica.");
      outtextxy (50, 370, "PERFIL ACADEMICO: Tener capacidad de entender las");
      outtextxy (50, 390, "nuevas tecnolog¡as a nivel de herdware y software.");
      getchar ();
}
//**************************************************************************//
void Ayuda ()
{
      cleardevice ();//limpiar pantalla unidad grafica
      setlinestyle(1, 0, 3);//define el estilo de la linea
      rectangle (2,2,getmaxx ()-2, getmaxy ()-2);//dibuja un rectangulo
      setlinestyle(2, 0, 2);
      rectangle (5,5,getmaxx ()-5, getmaxy ()-5);
      setlinestyle(1, 0, 3);
      rectangle (8,8,getmaxx ()-8, getmaxy ()-8);
      setbkcolor (MAGENTA);//define el color de fondo
      settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);//define el tama¤o tipo y orientacion del texto
      settextjustify (CENTER_TEXT, CENTER_TEXT);//justifica el texto
      outtextxy (getmaxx ()/2, 30, "Fundacion Universitaria San Martin");//imprime el texto en la coordenada especificada
      outtextxy (getmaxx ()/2, 60, "Ingenieria de Sistemas");
      outtextxy (getmaxx ()/2, 90, "Fisica 1");
      settextstyle(GOTHIC_FONT, HORIZ_DIR, 3);
      outtextxy (getmaxx ()/2, 150, "Ayuda del Programa");
      rectangle (38,188,getmaxx ()-38, getmaxy ()-48);
      rectangle (40,190,getmaxx ()-40, getmaxy ()-50);
      rectangle (42,192,getmaxx ()-42, getmaxy ()-52);
      setfillstyle(SOLID_FILL, 9);
      floodfill(108, 215, getcolor ());
      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
      settextjustify (LEFT_TEXT, CENTER_TEXT);//justifica el texto
      outtextxy (50, 210, "Digite el numero correspondiente a cada opcion");
      outtextxy (50, 250, "Para cada operacion siga los pasos que le");
      outtextxy (50, 270, "indica el programa.");
      outtextxy (50, 310, "Para salir de cualquier pantalla de visualizacion");
      outtextxy (50, 330, "como ‚sta, presione la tecla Intro o Enter");
      outtextxy (50, 370, "Para visualizar Mision, Vision, Perfil Ocupacional");
      outtextxy (50, 390, "y Academico escoja salir del programa.");
      getchar ();
}
//**************************************************************************//
void Menu ()
{
   char Opcion;
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");
   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }
   Ayuda ();
   do
   {
      cleardevice ();//limpiar pantalla unidad grafica
      setlinestyle(1, 0, 3);//define el estilo de la linea
      rectangle (2,2,getmaxx ()-2, getmaxy ()-2);//dibuja un rectangulo
      setlinestyle(2, 0, 2);
      rectangle (5,5,getmaxx ()-5, getmaxy ()-5);
      setlinestyle(1, 0, 3);
      rectangle (8,8,getmaxx ()-8, getmaxy ()-8);
      setbkcolor (MAGENTA);//define el color de fondo
      settextstyle(GOTHIC_FONT, HORIZ_DIR, 4);//define el tama¤o tipo y orientacion del texto
      settextjustify (CENTER_TEXT, CENTER_TEXT);//justifica el texto
      outtextxy (getmaxx ()/2, 30, "Fundacion Universitaria San Martin");//imprime el texto en la coordenada especificada
      outtextxy (getmaxx ()/2, 60, "Ingenieria de Sistemas");
      outtextxy (getmaxx ()/2, 90, "Fisica 1");
      settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
      outtextxy (getmaxx ()/2, 130, "Monica Espitia");
      outtextxy (getmaxx ()/2, 150, "Angelica Maria Guzman Falco");
      outtextxy (getmaxx ()/2, 170, "Sandra Cecilia Correa Idarraga");
      settextjustify (LEFT_TEXT, CENTER_TEXT);//justifica el texto
      rectangle (38,208,getmaxx ()-38, getmaxy ()-48);
      rectangle (40,210,getmaxx ()-40, getmaxy ()-50);
      rectangle (42,212,getmaxx ()-42, getmaxy ()-52);
      setfillstyle(SOLID_FILL, 9);
      floodfill(108, 215, getcolor ());
      outtextxy (65, 240, "1. Suma de Vectores (Componentes Unitarios)");
      outtextxy (65, 270, "2. Suma de Vectores (Componentes Rectangulares)");
      outtextxy (65, 300, "3. Producto Escalar");
      outtextxy (65, 330, "4. Producto Vectorial");
      outtextxy (65, 360, "5. Salir del programa");
      outtextxy (65, 390, "Digite la opcion que desea [   ]");
      do
      {
	 Opcion = getche ();
      } while ((Opcion != '1') && (Opcion != '2') && (Opcion != '3') && (Opcion != '4') && (Opcion != '5'));
      switch (Opcion)
      {
	 case '1': {
		      SumaVectorUnitario ();
		   };break;
	 case '2': {
		      SumaVectorRectangular ();
		   };break;
	 case '3': {
		      ProductoEscalar ();
		   };break;
	 case '4': {
		      ProductoVectorial ();
		   };break;
	 case '5': {
		      MisionVision ();
		   };break;
      }
   } while (Opcion != '5');
   closegraph();
}
