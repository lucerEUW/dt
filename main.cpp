#include <iostream>
#include <b15f/b15f.h>
#include <cmath>
#include <iomanip>
#include <fstream>

//board ansprechen
B15F& drv = B15F::getInstance();

int main()
{
	//modi auswahl via dipswitch
	int z = drv.readDipSwitch();
	if (z == 1)
	{
	
	//modi 1 mit 2variblen/1 logicgates
	//tabellen header		
	std::cout << std::setw(5) << "B" << "A" << "Y" << std::endl;
	for (int i = 0; i<=3; i++)
		{
			//input für logicgate
			drv.digitalWrite0(i);
			int a,b,x,y;
			
			//decimal in in binär
			x = i;
			a = x%2;
			x = x/2;
			b = x%2;
			
			//output lesen		
			y = drv.digitalRead0();
			
			//output mit inputvarianten in tabelle ausgeben
			std::cout << std::setw(5) << b << a << y << std::endl;
		}
	}
	else
	{
	//modi 2 mit 4 variablen/3 logicgates
		std::cout << std::setw(5) << "D" << "C" << "B" << "A" << " Y" << std::endl;
		for (int i = 0; i<=15; i++)
		{
			drv.digitalWrite0(i);
			int a,b,c,d,x,y;
			x = i;
			a = x%2;
			x = x/2;
			b = x%2;
			x = x/2;
			c = x%2;
			x = x/2;
			d = x%2;				
			y = drv.digitalRead0();
			std::cout << std::setw(5) << d << c << b << a <<" "<< y <<std::endl;
		}
	}
}
