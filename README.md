# Redes
### Prácticas de la asignatura de redes
#### Práctica 1. Programación de aplicaciones sobre TCP/IP

Se pide diseñar un servidor ```UDP``` que implemente un servicio similar al proporcionado por
*daytime*, así como un cliente que haga uso de su servicio. Como el servicio que ofrece ```UDP``` es no fiable tanto la petición como la respuesta pueden perderse, por lo que el cliente puede no recibir contestación.

El programa cliente realizará una petición al servidor y esperará la
respuesta un tiempo limitado (5 segundos). Si recibe la respuesta, enviará a la salida estándar el mensaje proporcionado por el servidor. Si después de ese tiempo no recibe una respuesta, volverá a mandar el mensaje al servidor para intentar recibir, si después de tres intentos no consigue nada, mostrará al usuario un mensaje de error. Tanto la dirección ```IP``` como el *timeout* se pasarán como argumentos.

El servicio admitirá la siguiente especificación de los paquetes:

  - **DAY**: paquete para solicitar el día de la maquina remota. La salida será con el siguiente formato: ```Lunes, 29 de Septiembre de 2014```

  - **TIME**: paquete para solicitar la hora de la maquina remota. La salida será con el
  siguiente formato: ```16:00:00```

  - **DAYTIME**: paquete para solicitar tanto el día como la hora de la maquina remota. La salida será con el siguiente formato: ```Lunes, 29 de Septiembre de 2014; 16:00:00.```

  ![](https://img.shields.io/badge/Practica%201-0%25-green.svg)

#### Práctica 2. El Buscaminas

Para jugar al buscaminas es necesario una cuadrícula que inicialmente aparece oculta y
una vez que se selecciona una cuadrícula, indica un número que representa las minas que hay en
ese contacto con ese recuadro, o una mina. Cada recuadro puede tocar un máximo de 8 minas. 
El jugador puede colocar una bandera en una celda para indicar que hay una mina, o seleccionarla
para descubrir lo que contiene.

  ![](https://img.shields.io/badge/Practica%202-0%25-red.svg)
