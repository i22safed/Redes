#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(){


     int Socket_Servidor;
     struct sockaddr_in Servidor;
     int contador = 0;
     char formato[80];
     time_t tiempo;
     struct tm * stTm;
     tiempo = time(NULL);
     stTm = localtime(&tiempo);

     struct sockaddr_in Cliente;
     socklen_t Longitud_Cliente;

     Socket_Servidor = socket (AF_INET, SOCK_DGRAM, 0);

     if (Socket_Servidor == -1){
          printf ("No se puede abrir socket servidor\n");
          exit (-1);
     }

     Servidor.sin_family = AF_INET;
     Servidor.sin_port = htons(2000);
     Servidor.sin_addr.s_addr = htonl(INADDR_ANY);

     if (bind (Socket_Servidor, (struct sockaddr *)&Servidor, sizeof (Servidor)) == -1){
          close (Socket_Servidor);
          exit (-1);
     }

     Longitud_Cliente = sizeof(Cliente);

          int recibido=0;

          if(recibido==0){


            recibido = recvfrom (Socket_Servidor, &contador, sizeof(contador), 0,
            (struct sockaddr *) &Cliente, &Longitud_Cliente);

               if (recibido > 0){

                    printf("Numero de servicio → %d\n",contador);

                    if(contador==1){
                         strftime(formato,80,"%A, %d de %B de %Y", stTm);
                    }
                    if(contador==2){
                         strftime(formato,80,"%H:%M:%S", stTm);
                    }
                    if(contador==3){
                         strftime(formato,80,"%A, %d de %B de %Y; %H:%M:%S", stTm);
                    }


                    int enviado = sendto (Socket_Servidor, &formato, sizeof(formato), 0,
                    (struct sockaddr *) &Cliente, Longitud_Cliente);


               }
          }

        close(Socket_Servidor);

       return 0;
     }
