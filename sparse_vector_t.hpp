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
		cout<<"El vector Disperso es: ";
		os << "[ " << setw(7) << sz_ << " ";
		v_.write(os);
		os << " ]";

		return os;
	}


/*el istream igual que el vector_t lo que sucede primer elemento a leer 
numero de elementos que tiene el vector hecho abajo por Riera

*/
	//devuelve v_ para poder acceder
	vector_pair_t getValue () const
	{
		return v_;
	}

	double scal_prod(const vector_t& v) const{
		
		double aux= 0;
		
		for(int i=0; i < v_.get_sz();i++)
			//Vec1  * Vec2
			aux += v_.get_v(i).get_val() * v.get_v(v_.get_v(i).get_inx());
		return aux;
	}
	
	

	double scal_prod_sparse(const sparse_vector_t& v) const
	{
		double aux = 0;
		for (int i=0; i< v_.get_sz();i++)
			
			for(int j=0; j<v.getValue().get_sz();j++)
				
				if(v_.get_v(i).get_inx() == v.getValue().get_v(j).get_inx())
					aux += v_.get_v(i).get_val() * v.getValue().get_v(j).get_val();
			
			return aux;
		
	}

	ostream& write_dense(ostream& os) const
	{
		os<<"El tamaño del vector es"<< setw(8)<< sz_<<endl;
		cout<<"El vector DISPERSO es ";
		for(int j=0; j< sz_;j++)
		
		{
			int inx=0;
			bool flag = false;
			do{
				if(v_.get_v(inx).get_inx()==j)
				{
					flag = true;
						os << setw(8) << fixed << setprecision(2) << v_.get_v(inx).get_val();
				}
				
				inx++;	
			
			}while((inx < v_.get_sz()));
			
			if(!flag)
				os << setw(8) << fixed << setprecision(2)<< "0.00";
		}
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

