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


int main(void) 
{
	//Entradas
	DDRB &= ~(1<<0); // PB0 = B0
	PORTB |= (1<<0); // Para ligar o pull-up
	
	//Saídas
	DDRB |= ((1<<1)|(1<<2)|(1<<3)|(1<<4)|(1<<5));
	

    while (1) 
    {
//
		//Escrevendo nas saídas para testar a simulação
		vm_on;
		am_on;
		vd_on;
		vmp_on;
		vdp_on;

	}
}