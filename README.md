# Redes
### Prácticas de la asignatura de redes
#### Práctica 1.

Se pide diseñar un servidor UDP que implemente un servicio similar al proporcionado por
daytime, así como un cliente que haga uso de su servicio. Como el servicio que ofrece UDP es
no fiable tanto la petición como la respuesta pueden perderse, por lo que el cliente puede no
recibir contestación.

El programa cliente realizará una petición al servidor y esperará la
respuesta un tiempo limitado (5 segundos). Si recibe la respuesta, enviará a la salida estándar el mensaje proporcionado por el servidor. Si después de ese tiempo no recibe una respuesta, volverá a mandar el mensaje al servidor para intentar recibir, si después de tres intentos noconsigue nada, mostrará al usuario un mensaje de error. Tanto la dirección IP como el timeout se pasarán como argumentos.

El servicio admitirá la siguiente especificación de los paquetes:

  - DAY: paquete para solicitar el día de la maquina remota. La salida será con el siguiente formato: Lunes, 29 de Septiembre de 2014

  - TIME: paquete para solicitar la hora de la maquina remota. La salida será con el
  siguiente formato: 16:00:00

  - DAYTIME: paquete para solicitar tanto el día como la hora de la maquina remota. La
  salida será con el siguiente formato: Lunes, 29 de Septiembre de 2014; 16:00:00.

  ![](https://img.shields.io/badge/Practica%201%20-0%25-red.svg)
