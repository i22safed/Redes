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


     int Socket_Cliente;
     int Servicio;
     char fecha[80];
     struct sockaddr_in Servidor;
     socklen_t Longitud_Servidor;

     Socket_Cliente = socket (AF_INET, SOCK_DGRAM, 0);

     if (Socket_Cliente == -1){
          printf ("No se puede abrir el socket cliente\n");
          exit (-1);
     }

     Servidor.sin_family = AF_INET;
     Servidor.sin_addr.s_addr =  inet_addr("127.0.0.1");
     Servidor.sin_port = htons(2000);

     Longitud_Servidor = sizeof(Servidor);

     printf("\nIntroduzca el servicio para la respuesta del servidor");
     printf("\n1. DAY → Fecha formato Dia, DD de MES de 201X");
     printf("\n2. TIME → Hora formato HH:MM:SS");
     printf("\n3. DAYTIME → DAY + TIME");
     printf("\nServicio: ");
     scanf("%i",&Servicio);

     // Datagrama
     int enviado = sendto (Socket_Cliente, (char *) &Servicio, sizeof(Servicio), 0,
     (struct sockaddr *) &Servidor, Longitud_Servidor);


     if (enviado < 0){
          printf("Error al solicitar el servicio\n");
     }else{
          int recibido = recvfrom (Socket_Cliente,fecha, sizeof(fecha), 0,
          (struct sockaddr *) &Servidor, &Longitud_Servidor);

     if (recibido > 0){
          printf ("Leido, servicio numero %i %s\n",Servicio,fecha);
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
cd code/Redes/practica1

*/
