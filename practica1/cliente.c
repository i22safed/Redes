#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

int main(){

     // Variable para la apertura del Socket
     int Socket_Cliente;

     // Esta variable será enviada al servidor (datos=rand()%10)
     int Datos;

     // Estructura para los datos del servidor del cual t
     struct sockaddr_in Servidor;

     //Variable que contendrá la longitud de la estructura
     socklen_t Longitud_Servidor;

     // Asignamos a la variable Socket_Cliente, la apertura del socket
     Socket_Cliente = socket (AF_INET, SOCK_DGRAM, 0);

     if (Socket_Cliente == -1){
          printf ("No se puede abrir el socket cliente\n");
          exit (-1);
     }

     // Asignamos la información a las variables de la estructura del socket
     // Familia/tipo de direcciones
     Servidor.sin_family = AF_INET;
     // Direccion IP
     Servidor.sin_addr.s_addr =  inet_addr("127.0.0.1");
     // Numero de puerto
     Servidor.sin_port = htons(2000);
     Longitud_Servidor = sizeof(Servidor);

     // Rellenamos la varibale para enviarla al servidor
     srand (time(NULL));
     Datos = rand()%20;
     printf ("Envio %d\n", Datos);


     // Control sobre envio/recepción
     // Enviado → sendTo(socketCliente → socketServidor)
     // Si enviado es menor que 0 no se ha enviado nada
     // Si No
          // Corfirmamos recepción → recvFrom(socketCliente → socketServidor)
          // Si recibido es mayor que 0 → Se ha leido
          // Si no
               // El servidor no lo ha leido

     int enviado = sendto (Socket_Cliente, (char *) &Datos, sizeof(Datos), 0,
     (struct sockaddr *) &Servidor, Longitud_Servidor);

     if (enviado < 0){
          printf("Error al solicitar el servicio\n");
     }else{
          int recibido = recvfrom (Socket_Cliente, (char *)&Datos, sizeof(Datos), 0,
          (struct sockaddr *) &Servidor, &Longitud_Servidor);

     if (recibido > 0){
          printf ("Leido %d\n", Datos);
     }else{
          printf ("Error al leer del servidor\n");
     }

     // Cierre del socket
     close(Socket_Cliente);
     return 0;
     }
}
/*

INFO → https://es.wikibooks.org/wiki/Programaci%C3%B3n_en_C/Sockets

*/
