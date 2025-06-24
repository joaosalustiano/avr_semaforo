#define F_CPU   16000000
#include <util/delay.h>
#include <avr/io.h>

//Definindo os estados ON e OFF de cada variável
//Pedestre
#define vmp_on PORTB |= (1<<1)
#define vmp_off PORTB &= ~(1<<1)

#define vdp_on PORTB |= (1<<2)
#define vdp_off PORTB &= ~(1<<2)

//Veículos
#define vm_on PORTB |= (1<<3)
#define vm_off PORTB &= ~(1<<3)

#define am_on PORTB |= (1<<4)
#define am_off PORTB &= ~(1<<4)

#define vd_on PORTB |= (1<<5)
#define vd_off PORTB &= ~(1<<5)

//Definindo as funções
void vermelho()
{
	vm_on;
	am_off;
	vd_off;
	vmp_off;
	vdp_on;
}

void amarelo()
{
	vm_off;
	am_on;
	vd_off;
	vmp_on;
	vdp_off;
}

void verde()
{
	vm_off;
	am_off;
	vd_on;
	vmp_off;
	vdp_off;
}

void pisca()
{
	vd_off;
	PORTB ^= (1<<1);
}


int main(void) 
{
	//Entradas
	DDRB &= ~(1<<0); // PB0 = B0
	PORTB |= (1<<0); // Para ligar o pull-up
	
	//Saídas
	DDRB |= ((1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5));
	unsigned int c = 0;

    while (1) 
    {
		if(c < 3000)
		{
			amarelo();
		}
		else if(c < 15000)
		{
			vermelho();
		}
		else if(c < 18000)
		{
			if((c % 500) == 0)
			{
				pisca();
			}
		}
		else if(c < 50000)
		{
			verde();
			if(!(PINB & (1<<0))) //B0
			{
				c = 50000;	
			}
		}
		else if(c < 60000)
		{
			verde();
		}
		_delay_ms(1);
		c++;
	}
}
