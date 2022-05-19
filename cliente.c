#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#ifdef WIN32
#include <winsock.h>
#else  // Linux, Unix
  #include <unistd.h>
  #include <netdb.h>
  #include <netinet/in.h>
  #include <sys/types.h>
  #include <sys/socket.h>
  #include <arpa/inet.h>
#endif


int main(int argc, char* argv[])
{ struct sockaddr_in server;	
  int sockfd,n;
  struct hostent *h;
  char MsgOperacao[128+1];
  char MsgCodigo[128+1];
  char MsgFilme[128+1];
  char szServidor[128+1];
  int nPorta;
  
  int finalizar;
   // Pare ser executado no ambiente winodws
  #ifdef WIN32
  WSADATA wsaData;
  int err;
  // "instanciar" a DLL winsock 
  err = WSAStartup( MAKEWORD( 2, 2 ), &wsaData );
#endif

    printf("Digite o ip onde está o servidor : ");
	gets(szServidor);
//    printf("Digite o numero da porta da servidor: ");
//	gets(szMsg);

//    nPorta = (int)atoi(szMsg);
    nPorta = 2000;
    finalizar = 0;
	while(!finalizar)
	{

      if((sockfd = socket(AF_INET,SOCK_STREAM,0)) == -1)
	  {
        printf("Nao consegui efetuar o socket.\n");
	  	return 0;
	  }

	  if((h = gethostbyname((char*)szServidor)) == NULL)
	  {
        printf("Nao consegui efetuar o gethostbyname para %s.\n",argv[1]);
		return 0;
	  }


    memset(&server,0,sizeof(server));

    server.sin_addr = *((struct in_addr*) h->h_addr);
	                  // tratamento do endiniase

	server.sin_port = htons(nPorta);
	server.sin_family = AF_INET;
	
    errno = 0;

	if(connect(sockfd,(struct sockaddr*)&server,sizeof(struct sockaddr)) == -1 )
	{
       printf("Não consegui efetuar o connect.\n");
	   return 0;
	}

    memset(&MsgOperacao,0,sizeof(MsgOperacao));
    printf("\nInforme a operação: ");
	gets(MsgOperacao);

	if(send(sockfd,(char*)MsgOperacao,strlen(MsgOperacao),0) <= 0) 
	{
       printf("Nao consegui efetuar o send.\n");
	   return 0;
	}
	
    memset(&MsgCodigo, 0, sizeof(MsgCodigo));
    printf("\nInforme o codigo do cliente: ");
	gets(MsgCodigo);

	if(send(sockfd,(char*)MsgCodigo,strlen(MsgCodigo),0) <= 0) 
	{
       printf("\n\n\nNao consegui efetuar o send.\n");
	   return 0;
	}
	
	memset(&MsgFilme,0,sizeof(MsgFilme));
    printf("\nInforme o nome filme: ");
	gets(MsgFilme);

	if(send(sockfd,(char*)MsgFilme,strlen(MsgFilme),0) <= 0) 
	{
       printf("\n\n\nNao consegui efetuar o send.\n");
	   return 0;
	}
	
	
	/*n = recv(sockfd,(char*)szMsg,sizeof(szMsg),0); 
	if(n < 0)
       printf("\n\nNao consegui efetuar o receiver.\n");
	else{
	    szMsg[n] = '\0';
        printf("\n\nNumero Aleatorio = %s\n\n\n\n",szMsg);
	}
	
    if (strcmp(szMsg,"FIM") == 0) {
           finalizar = 1;
    } */
	
}

#ifdef WIN32
	// para ser usado na plataforma windows
    closesocket (sockfd);
//	}
    WSACleanup ( );	
#else
    close( sockfd );
#endif

	return 0;
}

