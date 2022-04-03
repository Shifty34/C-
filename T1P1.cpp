#include <iostream>
#include <math.h>
using namespace std;
class Poly
{
private:
	int order;	//Degree of polynomial
	int *coeff; //Pointer to create dynamic array of co-efficients
public:
	Poly();						   //Default constructor
	Poly(int, int);				   //Parameterized Constructor
	Poly(int, int *);			   //Parameterized Constructor
	~Poly();					   //Destructor
	Poly(const Poly &);			   //copy constructor
	Poly &operator=(const Poly &); //Assignment Operator overloading
								   //Mutators and Accessors
	void show();
	void set(int[], int);
	int getOrder() const;
	int *get() const;
	//operator overloading
	Poly operator+(const Poly &);	  //Add two polynomial
	Poly operator-(const Poly &);	  //Substract two polynomial
	Poly operator*(const Poly &);	  //Multiply two polynomial
	Poly operator*(const int);		  //Multiply polynomial with constant
	bool operator==(const Poly &);	  //Check if two polynomial are equal
	const int &operator[](int) const; //Returns nth coefficient
	int &operator[](int n);			  //Returns nth coefficient(lhs)
	int operator()(int);			  //Evaluate P(x) accordingly
	friend ostream &operator<<(ostream &Out, const Poly &);
};

Poly::Poly()
{
	order = 0;
	coeff = new int[order + 1];
	coeff[0] = 1;
}
Poly::Poly(int Order, int Default)
{
	order = Order;
	coeff = new int[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = Default;
	}
}
Poly::Poly(int Order, int *Coeff)
{
	order = Order;
	coeff = new int[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = Coeff[i];
	}
}
Poly::~Poly()
{
	delete[] coeff;
	coeff = nullptr;
}
Poly::Poly(const Poly &rhs)
{
	order = rhs.order;
	coeff = new int[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = rhs.coeff[i];
	}
}
Poly &Poly::operator=(const Poly &rhs)
{
	order = rhs.order;
	coeff = new int[order + 1];
	for (int i = 0; i <= order; i++)
	{
		coeff[i] = rhs.coeff[i];
	}
	return *this;
}
void Poly::set(int coeff[], int size)
{
	order = size;
	for (int i = 0; i <= size; i++)
	{
		this->coeff[i] = coeff[i];
	}
}
int Poly::getOrder() const
{
	return order;
}
int *Poly::get() const
{
	return coeff;
}
Poly Poly::operator+(const Poly &rhs)
{
	Poly temp;
	int ch = 0;
	if (rhs.order <= order)
	{
		ch = rhs.order;
		temp = *this;
	}
	else
	{
		ch = order;
		temp = rhs;
	}
	for (int i = 0; i <= ch; i++)
	{
		temp.coeff[i] = coeff[i] + rhs.coeff[i];
	}
	return temp;
}
Poly Poly::operator-(const Poly &rhs)
{
	Poly temp;
	int ch = 0;
	if (rhs.order <= order)
	{
		ch = rhs.order;
		temp = *this;
	}
	else
	{
		ch = order;
		temp = rhs;
	}
	for (int i = 0; i <= ch; i++)
	{
		temp.coeff[i] = coeff[i] - rhs.coeff[i];
	}
	return temp;
}
Poly Poly::operator*(const int p)
{
	Poly temp(this->order, this->coeff);
	int ch = this->order;

	for (int i = 0; i <= ch; i++)
	{
		temp.coeff[i] = p * temp.coeff[i];
	}
	return temp;
}
bool Poly::operator==(const Poly &rhs)
{
	if (rhs.order != this->order)
	{
		return false;
	}
	else
	{
		int ch = this->order;
		for (int i = 0; i <= ch; i++)
		{
			if (rhs.coeff[i] != this->coeff[i])
			{
				return false;
			}
		}
		return true;
	}
}
int &Poly::operator[](int n)
{
	int ch = this->order;
	if (n <= ch)
	{
		return this->coeff[n];
	}
	return this->coeff[0];
}
const int &Poly::operator[](int i) const
{
	int ch = this->order;
	if (i <= ch)
	{
		return this->coeff[i];
	}
	return this->coeff[0];
}
int Poly::operator()(int x)
{
	int value = 0;
	for (int i = order; i >= 0; i--)
	{
		if (coeff[i] >= 0)
		{
			if (i == 0)
				value += 1;
			else
				value += pow(coeff[i], i);
		}
		else
		{
			if (i == 0)
				value += 1;
			else
				value += pow(coeff[i], i);
		}
	}
	return value;
}
Poly Poly::operator*(const Poly &rhs)
{
	int m = this->getOrder();
	int n = rhs.getOrder();
	int *prod = new int[m + n - 1];
	Poly multi(m + n - 1, 0);


	for (int i = 0; i < m + n - 1; i++)
		multi.coeff[i] = 0;



	for (int i = 0; i < m; i++)
	{

		for (int j = 0; j < n; j++)
			multi.coeff[i + j] += this->coeff[i] * rhs.coeff[j];
	}

	return multi;
}
void Poly::show()
{
	cout << "Polynomial : ";
	for (int i = order; i >= 0; i--)
	{
		if (coeff[i] >= 0)
		{
			if (i == 0)
				cout << "+" << coeff[i];
			else
				cout << "+" << coeff[i] << "x^" << i;
		}
		else
		{
			if (i == 0)
				cout << coeff[i];
			else
				cout << coeff[i] << "x^" << i;
		}
	}
	cout << endl;
}
ostream &operator<<(ostream &Out, const Poly &p)
{
	Out << "Polynomial : ";
	for (int i = p.getOrder(); i >= 0; i--)
	{
		if (p.coeff[i] >= 0)
		{
			if (i == 0)
				Out << "+" << p.coeff[i];
			else
				Out << "+" << p.coeff[i] << "x^" << i;
		}
		else
		{
			if (i == 0)
				Out << p.coeff[i];
			else
				Out << p.coeff[i] << "x^" << i;
		}
	}
	Out << endl;
	return Out;
}

int main()
{

string Name;
	/*****************************************/
cout << "Student Enter Name" << endl;
cin >> Name;
cout << "----------------------------------------------" << endl;
cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
cout << "Student Name: " << Name << endl;
cout << "----------------------------------------------" << endl;
	/*****************************************/


	int order = 0, *arr = 0;


	cout << "Enter the degree of Polynomial : ";
	cin >> order;
	arr = new int[order + 1];
	cout << "Enter the elements " << endl;
	for (int i = 0; i <= order; i++)
	{
		cout << "For x^" << i << " :";
		cin >> arr[i];
	}
	Poly P1(order, arr);
	Poly P2;
	P1.show();
	cout << "Enter the degree of Polynomial : ";
	cin >> order;
	arr = new int[order + 1];
	cout << "Enter the elements " << endl;
	for (int i = 0; i <= order; i++)
	{
		cout << "For x^" << i << " :";
		cin >> arr[i];
	}
	P2.set(arr, order);
	P2.show();
	Poly P3;
	P3 = P1;
	cout << "P3: ";
	P3.show();
	P3 = P1 + P2;
	P3.show();
	P3 = P1 - P2;
	P3.show();
	P3 = P1 * 10;
	P3.show();
	cout << P3;
	int Value = P2[5];
	P1[3] = Value;
	cout << "P1[3]: " << P1[3] << endl;
	int Z = P1(5);
	cout << "P1(5) = " << Z << endl;
	P3 = P1 * P2;
	cout << P3;
	bool flag = (P1==P2);
	cout << "Are the two Polynomials equal? " << flag << endl;
}

