#include<stdio.h>
#include<stdlib.h>


struct cel
{
	int conteudo;
	struct cel *prox;
};

typedef struct cel celula;

celula *inicio,*novo;

void inserefim(int valor);
void crialista(void);
void imprime(void);
void inserePosicaoCerta(int);
void ordenarLista (void);
void troca(celula *p, celula *q);
int buscaPosicao(int);
int tamanho(void);
void insereInicio(int);
void removeFim(void);

main()
{
	int valor,i;

	crialista();

	for (i=0;i<5;i++)
	{
		printf("Valor %d: ",i+1);
		scanf("%d",&valor);
		inserefim(valor);
	}

	imprime();
	printf("Tamanho %d: \n",tamanho());
	printf("Posicao %d: \n",buscaPosicao(5));
	ordenarLista();
	imprime();
	inserePosicaoCerta(6);
	printf("Tamanho %d: \n",tamanho());
	imprime();
	removeInicio();
	removeInicio();
	imprime();
	removeValor(4);
	imprime();




	system ("pause");
	return 0;
}

void crialista(void)
{
	inicio=NULL;
}

void troca(celula *p, celula *q){
    int temp;
    temp=p->conteudo;
    p->conteudo=q->conteudo;
    q->conteudo=temp;
}

void ordenarLista()
{
    int i,j,tamanho1;
    celula *p;
	p=inicio;
	tamanho1=tamanho();


	for (i=1;i<=tamanho1;i++){
        for (j=1;j<=tamanho1-1;j++){
            if (p->conteudo>p->prox->conteudo)
                {
                troca(p,p->prox);
                p=p->prox;
                }


        }
    p=inicio;
	}

}

void removeInicio(){
 celula *p,*temp;
 p=inicio;

 temp=p;

 inicio=p->prox;
 free(temp);

}

int posicao(int valor){
 celula *p;
 p=inicio;
 int i,posicao;

 int tam=tamanho();

 for (i=1;p->conteudo<valor;i++){
    p=p->prox;
 }


 return i;


}

void removeValor(int valor){
celula *p,*temp1,*temp2;
p=inicio;
int i;
int pos=posicao(valor);
for (i=1;i<pos;i++){
        p=p->prox;
    }
//temp1=p;
temp1=p->prox;
temp2=temp1->prox;
p->prox=temp2;
free(temp1);




}

void inserePosicaoCerta(int valor){
    celula *p,*novo1;
    int i,pos
    ;
	p=inicio;
	novo1=(celula *)malloc(sizeof(celula));
	novo1->conteudo=valor;
	novo1->prox=NULL;

	if(inicio==NULL)
	{
		inicio=novo1;
	}

pos=posicao(valor)-1;

    for (i=1;i<pos;i++){
        p=p->prox;
    }

novo1->prox=p->prox;
p->prox=novo1;



}

void inserefim(int valor)
{
	celula *p,*novo1;
	p=inicio;

	novo1=(celula *)malloc(sizeof(celula));
	novo1->conteudo=valor;
	novo1->prox=NULL;


	if(inicio==NULL)
	{
		inicio=novo1;
		return;
	}

    while(p->prox!=NULL)
		{
        p=p->prox;
		}
    p->prox=novo1;

}

int buscaPosicao(int valor)
{
    celula *p;
    p=inicio;
    int i=1;
    if (inicio->conteudo==valor)
        return 1;

      while(p!=NULL)
		{
		    if(p->conteudo==valor)
            {
                return i;
            }

        p=p->prox;
        i++;
		}
    return 0;
}

 void removeFim()
{
	celula *p;
	p=inicio;

	for(p=inicio;p->prox->prox!=NULL;p=p->prox)
	{
		if(p->prox->prox=NULL)
		{
		free(p->prox);
		p->prox=NULL;

		}

	}

}

 void insereInicio(int valor)
{
	celula *p;
	p=inicio;

	if(p!=NULL)
	{
		novo=(celula *)malloc(sizeof(celula));
		novo->conteudo=valor;
		novo->prox=p;
		inicio=novo;

	}
}

int tamanho(void)
{
	int tamanho=0;
	celula *p;
	for(p=inicio;p!=NULL;p=p->prox)
	{
		tamanho++;
	}
	return tamanho;
}

void imprime(void)
{
	celula *p;
	for(p=inicio;p!=NULL;p=p->prox)
	{
			printf("OS VALORES SAO: %d\n",p->conteudo);
	}
	printf("****************\n");
}
