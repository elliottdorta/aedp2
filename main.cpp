#include "vector_t.hpp"
#include "sparse_vector_t.hpp"

#include <iostream>
#include <fstream>
using namespace std;

#define V_SZ 10000
#define EPS  1E-3

int main(int argc, char* argv[])
{

	if (argc != 4)
	{
		cerr << "Usage: " << argv[0] << " vector1.txt vector2.txt" << endl;
		return -1;
	}

	ifstream vector1;
	ifstream vector2;
	ifstream vector3;
	
	vector1.open(argv[1]);
	vector2.open(argv[2]); 
	vector3.open(argv[3]);

	vector_t v1;
	sparse_vector_t v2;	
	sparse_vector_t v3;	

	v1.read(vector1);
	v2.read(vector2);
	v3.read(vector3);

	v1.write(cout);
        cout << endl;
	v2.write_dense(cout);
	cout << endl;
	const double sp = v2.scal_prod(v1);
	const double sp_sparse = v2.scal_prod_sparse(v3);
	cout<<endl;
	cout << "La maquina de la verdad dice que el producto escalar es: " << sp << endl;
	
	cout << "La maquina de la verdad dice que el producto escalar Disperso es: " << sp_sparse << endl;

	vector1.close();
	vector2.close();
	vector3.close();


}
