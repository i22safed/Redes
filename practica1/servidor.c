#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

     // Variable para la apertura del Socket
     int Socket_Servidor;

     // Estructura necesaria para los datos del servidor
     struct sockaddr_in Servidor;

     // En este caso solo tenemos que recibir mensajes, es decir, leer mensajes
     // por lo tanto no necesario variable datos
     int contador = 0;

     // Información sobre el cliente que quiere recibir
     struct sockaddr_in Cliente;
     socklen_t Longitud_Cliente;

     // Abrimos el socketServidor
     Socket_Servidor = socket (AF_INET, SOCK_DGRAM, 0);

     if (Socket_Servidor == -1){
          printf ("No se puede abrir socket servidor\n");
          exit (-1);
     }

     // Asignamos la información a las variables de la estructura del socket
     // Familia/tipo de direcciones
     Servidor.sin_family = AF_INET;
     // Numero de puerto
     Servidor.sin_port = htons(2000);
     // Direccion IP, INADDR_ANY → Macro que especifica nuestra direccion
     Servidor.sin_addr.s_addr = htonl(INADDR_ANY);

     // Asigna un Socket a un puerto
     if (bind (Socket_Servidor, (struct sockaddr *)&Servidor, sizeof (Servidor)) == -1){
          close (Socket_Servidor);
          exit (-1);
     }

     // Asignamos el tamaño del cliente para el recvfrom
     Longitud_Cliente = sizeof(Cliente);


          // Mientras la condicion del while sea 1
          while (1){

            // Recibir mensajes del servidor
            int recibido = recvfrom (Socket_Servidor, &contador, sizeof(contador), 0,
            (struct sockaddr *) &Cliente, &Longitud_Cliente);

               if (recibido > 0){

                    printf ("Recibido %d, envio %d\n", contador, contador+1);
                    contador++;
                    // Funcion complementaria en la que enviamos la confrimacion
                    int enviado = sendto (Socket_Servidor, &contador, sizeof(contador), 0,
                    (struct sockaddr *) &Cliente, Longitud_Cliente);

               }
          }

        // Cerramos la conexión del servidor 
        close(Socket_Servidor);

       return 0;
     }
