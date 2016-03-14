#pragma once

#include <cstdio>
#include <iostream>
#include <iomanip>

#include <cassert>

using namespace std;

class vector_t{
private:
	double* v_;
	int     sz_;

public:

	vector_t(void):
		v_(NULL),
		sz_(0) {}

	vector_t(int sz):
		v_(NULL),
		sz_(sz) {

		crea_vector();
	}

	~vector_t(void){

		destruye_vector();
	}

	void resize(int sz)
	{
		destruye_vector();
		sz_ = sz;
		crea_vector();
	}

	int get_sz(void) const
	{
		return sz_;
	}

	double get_v(int pos) const{
		
		assert((pos < sz_) && ((pos >= 0)));

		return v_[pos];
	}

	double& get_set_v(int pos){

		assert((pos < sz_) && ((pos >= 0)));

		return v_[pos];
	}


	double scal_prod(const vector_t& v) const{
		
		double aux= 0;
		for(int i=0; i <= get_sz();i++)
			aux += v_[i] * v.get_v(i);
		return aux;
	}
	//MUestra por pantalla formateando
	ostream& write(ostream& os) const{
	
		os << setw(8) <<  sz_ << endl;

		for(int i = 0; i < sz_; i ++)
		 	os << setw(8) << fixed << setprecision(2) << v_[i] << " ";


		return os;
	}

	istream& read(istream& is){
	
		is >> sz_;

		resize(sz_);

		for(int i = 0; i < sz_; i ++)
		 	is >> v_[i];

		return is;
	}

private:

	void crea_vector(void){
		v_ = new double[sz_];
	}

	void destruye_vector(void)
	{
		if (v_ != NULL){
			delete [] v_;
			v_ = NULL;
		}
	}

};
