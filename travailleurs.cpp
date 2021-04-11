#include "travailleurs.hpp"
#include <iostream>

travailleurs::travailleurs():Ouvriers(145,ouvrier()){}

travaileurs::requiert_ouvriers(int nombre_ouvriers)
{
	val = false;
	if (Ouvriers.size() >= nombre_ouvriers)
	{

		Ouvriers.erase(Ouvriers.begin(),Ouvriers.begin()+nombre_ouvriers);
		val = true;

	}
	return val;

}
