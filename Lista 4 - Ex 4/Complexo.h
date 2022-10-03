#ifndef COMPLEXO_H_INCLUDED
#define COMPLEXO_H_INCLUDED

#include <iostream>

class Complexo {
	private:
		float real_1, imagin_1, real_2, imagin_2;
		int op;
		void Soma();
		void Subtracao();
		void Multiplicacao();
		void Divisao();
		bool TestaValores(float real, float imaginario);
	public:
		void RecebeValores();
		void SelectOp();
		~Complexo();
};


#endif // COMPLEXO_H_INCLUDED
