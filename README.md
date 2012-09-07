Wii_Remote_Camera_Mouse
=======================

Mouse USB realizado con una camara de control de Nintendo Wii.

El directorio llamado "Wii_Remote_Camera_Mouse" contiene el sketch para el
arduino, ese se puede copiar al directorio de sketchbook del arduino IDE.

El directorio llamado "PVision" contiene la libreria para controlar la camara
del Wii Remote. Esa debe ir en un directorio llamado "libraries" dentro del
sketchbook del Arduino IDE.

El archivo "HID.cpp" reemplaza al que se encuentra en el directorio siguiente
dentro del Arduino IDE (para Leonardo): "hardware/arduino/cores/arduino/".
En el caso del Arduino Pro Micro de Sparkfun, este se debe de reemplazar por el
archivo del mismo nombre que se encuentra en la misma ruta, pero dentro del
add-on correspondiente (disponible en https://www.sparkfun.com/products/10999).

Nota: Se recomienda guardar copia del archivo HID.cpp original, puesto que se
modifica el descriptor USB y otros sketches podrian no funcionar bien. Si se
cuenta con una version mas reciente del archivo, entonces se recomienda editar
la linea resaltada con una flecha (buscar "<--" en la copia de este
repositorio) y cambiar el descriptor USB acordemente para cambiar el reporte de
coordenadas de relativo a absoluto.

Licencia
========

Este trabajo se hace publico bajo la licencia Creative Commons, en modalidad de
atribucion y comparticion bajo los mismos terminos. Se permite el uso comercial.

Para mas informacion:
http://creativecommons.org/licenses/by-sa/3.0/

Creditos
========
Muchisimas gracias a Steve Hobley por publicar el proyecto original de conectar
una camara de Wii Remote a un arduino, y por compartir su libreria llamada
PVision.

La version de PVision contenida en este repositorio ha sido actualizada para
trabajar con Arduino Version 1.0.1, asi que tecnicamente hemos hecho un fork,
aun cuando las modificaciones son menores

Puede encontrarse la version original de la libreria aca:
http://www.stephenhobley.com/blog/2009/03/01/pixartwiimote-sensor-library-for-arduino/
