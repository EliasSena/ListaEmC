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

main()
{
	int valor,i;

	crialista();

	for (i=0;i<5;i++)
	{
		printf("Valor %d: ",i);
		scanf("%d",&valor);
		inserefim(valor);
	}

	imprime();

	system ("pause");
	return 0;
}

void crialista(void)
{
	inicio=NULL;
}

void inserefim(int valor)
{
	celula *p;
	p=inicio;
	
	novo=(celula *)malloc(sizeof(celula));
	novo->conteudo=valor;
	novo->prox=NULL;
	

	if(inicio==NULL)
	{
		inicio=novo;
	}
	else
	{
	
		while(p!=NULL)
		{
		
			if (p->prox==NULL)
			{
				p->prox=novo;
			}
			else
			{
				p=p->prox;
			}
		}
	}
		
	
	
	/*
	if(inicio=NULL)
	{
		inicio=novo;
	}
	else
		for(p=inicio;p->prox!=NULL;p=p->prox)
		{
				if(p->prox=NULL)
			{
				p->prox=novo;		
			}	
		
		}	
	*/
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
}
