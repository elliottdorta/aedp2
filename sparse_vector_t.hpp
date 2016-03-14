#pragma once

#include "pair_t.hpp"
#include "vector_pair_t.hpp"
#include "vector_t.hpp"

#include <cmath>

#include <iostream>
#include <iomanip>

using namespace std;

class sparse_vector_t{
private:
	vector_pair_t v_;    // Vector de pares
	int           sz_;   // Tamaño del vector original

public:
	sparse_vector_t(void):
		v_(),
		sz_(0) {}

	sparse_vector_t(const vector_t& v, double eps):
		v_(),
		sz_(v.get_sz()) {
			
		// Cuenta el número de elementos no nulos
		int nz = 0;

		for(int i = 0; i < v.get_sz(); i++)
			if ( is_not_zero(v.get_v(i), eps) )
				nz ++;

		v_.resize(nz);

		nz = 0;

		for(int i = 0; i < v.get_sz(); i++)
			if ( is_not_zero(v.get_v(i), eps) )
			{
				v_.get_set_v(nz).set(i, v.get_v(i));
				nz ++;
			}		

	}

	~sparse_vector_t(void){}

	ostream& write(ostream& os) const{
	
		os << "[ " << setw(7) << sz_ << " ";
		v_.write(os);
		os << " ]";

		return os;
	}


/*el istream igual que el vector_t lo que sucede primer elemento a leer 
numero de elementos que tiene el vector hecho abajo por Riera

*/


		double scal_prod(const vector_t& v) const{
		
		double aux= 0;
		double vect1 = 0;
		double vect2 = 0;
		
		for(int i=0; i < v_.get_sz();i++)
		{
				vect1 = v_.get_v(i).get_val();
				vect2 =v.get_v(v_.get_v(i).get_inx());
				aux += vect1 * vect2;
				
		}
		return aux;
	}
	



	istream& read(istream& is)
	{
		is >> sz_;
		v_.read(is);
		
		return is;
	}



private:
	bool is_not_zero(double val, double eps) { return fabs(val) > eps;}

};

