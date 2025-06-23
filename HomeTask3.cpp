#include <iostream>
#include <windows.h>
#include <string>


using namespace std;

class Shape
{
protected:
	string name;
	int side_number = 0;

public:
	Shape() = default;
	Shape(string setName, int setSideNumber) : name{ setName }, side_number{ setSideNumber }{}
	Shape(string setName) { name = setName; };

	virtual string get_name()
	{
		return name = "Фигура";
	}

	virtual int get_side_number()
	{
		return side_number = 0;
	}

	virtual bool check()
	{
		if (side_number == 0) return true;
	};

	virtual void print_info()
	{
		string check_result = "";
		cout << get_name() << endl;
		if (check() == true) check_result = "Правильная";
		else check_result = "Неправильная";
		cout << check_result << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
	};
};

class Triangle : public Shape
{
protected:
	int a_side = 0;
	int b_side = 0;
	int c_side = 0;

	int angle_A = 0;
	int angle_B = 0;
	int angle_C = 0;

public:
	Triangle() : Shape() {};
	Triangle(int setA_side, int setB_side, int setC_side, int setAngle_A, int setAngle_B, int setAngle_C, string setName= "Треугольник:") : a_side{ setA_side }, b_side{ setB_side }, c_side{ setC_side }, angle_A{ setAngle_A }, angle_B{ setAngle_B }, angle_C{ setAngle_C }, Shape(setName){}
	Triangle(int setA_side, int setB_side, int setC_side, int setAngle_A, int setAngle_B, string setName) : a_side{ setA_side }, b_side{ setB_side }, c_side{ setC_side }, angle_A{ setAngle_A }, angle_B{ setAngle_B }, Shape(setName){}
	Triangle(int setA_side, int setB_side, int setAngle_A, int setAngle_B, string setName) : a_side{ setA_side }, b_side{ setB_side }, angle_A{ setAngle_A }, angle_B{ setAngle_B }, Shape(setName){}
	Triangle(int setA_side, int setAngle_A, string setName) : a_side{ setA_side }, angle_A{ setAngle_A }, Shape(setName){}

	string get_name() override
	{
		return name = "Треугольник:";
	}

	int get_side_number() override
	{
		return side_number = 3;
	}
	virtual void get_sides(int setA_side, int setB_side, int setC_side)
	{
		a_side = setA_side;
		b_side = setB_side;
		c_side = setC_side;
	}
	virtual void get_angles(int setAngle_A, int setAngle_B, int setAngle_C)
	{
		angle_A = setAngle_A;
		angle_B = setAngle_B;
		angle_C = setAngle_C;
	}
	bool check()override
	{
		if ((angle_A + angle_B + angle_C == 180) && (get_side_number() ==3))
			return true;
	};
	void print_info() override
	{
		string check_result = "";
		cout << get_name() << endl;
		if (check() == true) check_result = "Правильная";
		else check_result = "Неправильная";
		cout << check_result << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + "\n";
	};
};

class RangleTriangle : public Triangle
{
protected:
	int angle_C = 90;
public:
	RangleTriangle() :Triangle() {};
	RangleTriangle(int setA_side, int setB_side, int setC_side, int setAngle_A, int setAngle_B, string setName = "Прямоугольный треугольник:") :Triangle(setA_side, setB_side, setC_side, setAngle_A, setAngle_B, setName) {}

	string get_name() override
	{
		return name = "Прямоугольный треугольник:";
	}
	int get_side_number() override
	{
		return side_number = 3;
	}
	bool check() override
	{
		if ((angle_A + angle_B + angle_C == 180) && (get_side_number() == 3)&&(angle_C == 90))
			return true;
	};

	void get_sides(int setA_side, int setB_side, int setC_side) override
	{
		a_side = setA_side;
		b_side = setB_side;
		c_side = setC_side;
	}
	void get_angles(int setAngle_A, int setAngle_B)
	{
		angle_A = setAngle_A;
		angle_B = setAngle_B;
	}

	void print_info() override
	{
		string check_result = "";
			cout <<get_name() << endl;
			if (check() == true) check_result = "Правильная";
			else check_result = "Неправильная";
			cout << check_result << endl;
			cout << "количество сторон: " << get_side_number() << endl;
			cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + "\n";
			cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + "\n";
	};

};

class IsoscelesTriangle : public Triangle
{
public:
	IsoscelesTriangle() :Triangle() {};
	IsoscelesTriangle(int setA_side, int setB_side, int setAngle_A, int setAngle_B, string setName = "Равнобедренный треугольник:") :Triangle(setA_side, setB_side, setAngle_A, setAngle_B, setName) {}
	IsoscelesTriangle(int setA_side, int setAngle_A, string setName) :Triangle(setA_side, setAngle_A, setName) {}

	string get_name() override
	{
		return name = "Равнобедренный треугольник:";
	}
	int get_side_number() override
	{
		return side_number = 3;
	}
	void get_sides(int setA_side, int setB_side)
	{
		a_side = setA_side;
		b_side = setB_side;
		c_side = setA_side;
	}
	void get_angles(int setAngle_A, int setAngle_B)
	{
		angle_A = setAngle_A;
		angle_B = setAngle_B;
		angle_C = setAngle_A;
	}
	bool check() override
	{
		if ((angle_A + angle_B + angle_C == 180) && (get_side_number() == 3) && (a_side== c_side)&& (angle_A== angle_C))
			return true;
	};
	void print_info() override
	{
		string check_result = "";
		cout << get_name() << endl;
		get_sides(a_side, b_side);
		get_angles(angle_A, angle_B);
		if (check() == true) check_result = "Правильная";
		else check_result = "Неправильная";
		cout << check_result << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + "\n";
	};
};

class EquilateralTriangle : public IsoscelesTriangle
{
protected:
	int angle_A = 60;
	int angle_B = 60;
	int angle_C = 60;
public:
	EquilateralTriangle() :IsoscelesTriangle() {};
	EquilateralTriangle(int setA_side, int setAngle_A, string setName= "Равносторонний треугольник:") :IsoscelesTriangle(setA_side, setAngle_A, setName) {}

	string get_name() override
	{
		return name = "Равносторонний треугольник:";
	}

	void get_sides(int setA_side)
	{
		a_side = setA_side;
		b_side = setA_side;
		c_side = setA_side;
	}
	void get_angles()
	{

	}
	bool check() override
	{
		if ((angle_A + angle_B + angle_C == 180) && (get_side_number() == 3) && (a_side == c_side) && (a_side == b_side) && (angle_A == angle_C)&& (angle_A == angle_B))
			return true;
	}
	void print_info() override
	{
		string check_result = "";
		cout << get_name() << endl;
		get_sides(a_side);
		if (check() == true) check_result = "Правильная";
		else check_result = "Неправильная";
		cout << check_result << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + "\n";
	}
};

class Quadrangle : public Shape
{
protected:
	int a_side = 0;
	int b_side = 0;
	int c_side = 0;
	int d_side = 0;

	int angle_A = 0;
	int angle_B = 0;
	int angle_C = 0;
	int angle_D = 0;
public:
	Quadrangle() : Shape() {};
	//4 стороны 4 угла
	Quadrangle(int setA_side, int setB_side, int setC_side, int setD_side, int setAngle_A, int setAngle_B, int setAngle_C, int setAngle_D, string setName = "Четырёхугольник:"
	) : a_side{ setA_side }, b_side{ setB_side }, c_side{ setC_side }, d_side{ setD_side }, angle_A{ setAngle_A }, angle_B{ setAngle_B }, angle_C{ setAngle_C }, angle_D{ setAngle_D }, Shape(setName){}
	//2 стороны 2 угла
	Quadrangle(int setA_side, int setB_side, int setAngle_A, int setAngle_B, string setName
	) :  a_side{ setA_side }, b_side{ setB_side }, angle_A{ setAngle_A }, angle_B{ setAngle_B }, Shape(setName){}
	//2 стороны 1 угол=90
	Quadrangle(int setA_side, int setB_side, string setName
	) : a_side{ setA_side }, b_side{ setB_side }, Shape(setName){}
	//1 сторона 2 угла
	Quadrangle(int setA_side, int setAngle_A, int setAngle_B, string setName) : a_side{ setA_side }, angle_A{ setAngle_A }, angle_B{ setAngle_B }, Shape(setName){}
	//1 сторона 1 угол=90
	Quadrangle(int setA_side, string setName) : a_side{ setA_side }, Shape(setName){}

	string get_name() override
	{
		return name = "Четырёхугольник:";
	}

	int get_side_number() override
	{
		return side_number = 4;
	}
	void get_sides(int setA_side, int setB_side, int setC_side, int setD_side)
	{
		a_side = setA_side;
		b_side = setB_side;
		c_side = setC_side;
		d_side = setD_side;
	}
	void get_angles(int setAngle_A, int setAngle_B, int setAngle_C, int setAngle_D)
	{
		angle_A = setAngle_A;
		angle_B = setAngle_B;
		angle_C = setAngle_C;
		angle_D = setAngle_D;
	}
	bool check() override
	{
		if ((angle_A + angle_B + angle_C + angle_D == 360) && (get_side_number() == 4))
			return true;
	}
	void print_info() override
	{
		string check_result = "";
		cout << get_name() << endl;
		//get_sides();
		//get_angles();
		if (check() == true) check_result = "Правильная";
		else check_result = "Неправильная";
		cout << check_result << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + " d = " + to_string(d_side)+"\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + " D = " + to_string(angle_D)+"\n";
	}
};
class Parallelogram :public Quadrangle
{
public:
	Parallelogram() :Quadrangle() {};
	Parallelogram(int setA_side, int setB_side, int setAngle_A, int setAngle_B, string setName = "Параллелограмм:") :Quadrangle(setA_side, setB_side, setAngle_A, setAngle_B, setName) {}//параллелограмм
	Parallelogram(int setA_side, int setB_side, string setName) :Quadrangle(setA_side, setB_side, setName) {}//прямоугольник
	Parallelogram(int setA_side, int setAngle_A, int setAngle_B, string setName) :Quadrangle(setA_side, setAngle_A, setAngle_B, setName) {}//ромб
	Parallelogram(int setA_side, string setName) :Quadrangle(setA_side, setName) {}//квадрат

	string get_name() override
	{
		return name = "Параллелограмм:";
	}
	void get_sides(int setA_side, int setB_side)
	{
		a_side = setA_side;
		b_side = setB_side;
		c_side = setA_side;
		d_side = setB_side;
	}
	void get_angles(int setAngle_A, int setAngle_B)
	{
		angle_A = setAngle_A;
		angle_B = setAngle_B;
		angle_C = setAngle_A;
		angle_D = setAngle_B;
	}
	bool check() override
	{
		if ((angle_A + angle_B + angle_C + angle_D == 360) && (get_side_number() == 4)&& (a_side == c_side) && (b_side == d_side) && (angle_A == angle_C) && (angle_B == angle_D))
			return true;
	}
	void print_info() override
	{
		string check_result = "";
		cout << get_name() << endl;
		get_sides(a_side, b_side);
		get_angles(angle_A, angle_B);
		if (check() == true) check_result = "Правильная";
		else check_result = "Неправильная";
		cout << check_result << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + " d = " + to_string(d_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + " D = " + to_string(angle_D) + "\n";
	}
};

class Rectangl :public Parallelogram
{
protected:
	int angle_A = 90;
	int angle_B = 90;
	int angle_C = 90;
	int angle_D = 90;
public:
	Rectangl() :Parallelogram() {};
	Rectangl(int setA_side, int setB_side, string setName = "Прямоугольник:") :Parallelogram(setA_side, setB_side, setName) {}//прямоугольник
	Rectangl(int setA_side, string setName) :Parallelogram(setA_side, setName) {}//квадрат

	string get_name() override
	{
		return name = "Прямоугольник:";
	}
	void get_sides(int setA_side, int setB_side)
	{
		a_side = setA_side;
		b_side = setB_side;
		c_side = setA_side;
		d_side = setB_side;
	}
	void get_angles()
	{
	}
	bool check() override
	{
		if ((a_side == c_side) && (b_side == d_side) && (angle_A == angle_C) && (angle_B == angle_D) && (angle_A == angle_D) && (angle_B == 90))
			return true;
	}
	void print_info() override
	{
		string check_result = "";
		cout << get_name() << endl;
		get_sides(a_side, b_side);
		//get_angles();
		if (check() == true) check_result = "Правильная";
		else check_result = "Неправильная";
		cout << check_result << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + " d = " + to_string(d_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + " D = " + to_string(angle_D) + "\n";
	}
};

class Square :public Rectangl
{
protected:
	int angle_A = 90;
	int angle_B = 90;
	int angle_C = 90;
	int angle_D = 90;
public:
	Square() :Rectangl() {};
	Square(int setA_side, string setName = "Квадрат:") :Rectangl(setA_side, setName) {}//квадрат

	string get_name() override
	{
		return name = "Квадрат:";
	}
	void get_sides(int setA_side)
	{
		a_side = setA_side;
		b_side = setA_side;
		c_side = setA_side;
		d_side = setA_side;
	}
	void get_angles()
	{
	}
	bool check() override
	{
		if ((a_side == c_side) && (b_side == d_side) && (a_side == d_side) && (angle_A == angle_C) && (angle_B == angle_D) && (angle_A == angle_D) && (angle_B == 90))
			return true;
	}
	void print_info() override
	{
		string check_result = "";
		cout << get_name() << endl;
		get_sides(a_side);
		//get_angles();
		if (check() == true) check_result = "Правильная";
		else check_result = "Неправильная";
		cout << check_result << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + " d = " + to_string(d_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + " D = " + to_string(angle_D) + "\n";
	}
};

class Rhomb :public Parallelogram
{
public:
	Rhomb() :Parallelogram() {};
	Rhomb(int setA_side, int setAngle_A, int setAngle_B, string setName = "Ромб:") :Parallelogram(setA_side, setAngle_A, setAngle_B, setName) {}//ромб

	string get_name() override
	{
		return name = "Ромб:";
	}
	void get_sides(int setA_side, int setB_side)
	{
		a_side = setA_side;
		b_side = setA_side;
		c_side = setA_side;
		d_side = setA_side;
	}
	void get_angles(int setAngle_A, int setAngle_B)
	{
		angle_A = setAngle_A;
		angle_B = setAngle_B;
		angle_C = setAngle_A;
		angle_D = setAngle_B;
	}
	bool check() override
	{
		if ((a_side == c_side) && (b_side == d_side) && (a_side == d_side) && (angle_A == angle_C) && (angle_B == angle_D))
			return true;
	}
	void print_info() override
	{
		string check_result = "";
		cout << get_name() << endl;
		get_sides(a_side, b_side);
		get_angles(angle_A, angle_B);
		if (check() == true) check_result = "Правильная";
		else check_result = "Неправильная";
		cout << check_result << endl;
		cout << "Количество сторон: " << get_side_number() << endl;
		cout << "Стороны: а = " + to_string(a_side) + " b = " + to_string(b_side) + " c = " + to_string(c_side) + " d = " + to_string(d_side) + "\n";
		cout << "Углы: A = " + to_string(angle_A) + " B = " + to_string(angle_B) + " C = " + to_string(angle_C) + " D = " + to_string(angle_D) + "\n";
	}
};
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Shape shape1;
	shape1.print_info();
	cout << endl;
	cout << endl;

	Triangle triangle1(10,20,30,50,60,70);
	triangle1.print_info();
	cout << endl;
	cout << endl;

	RangleTriangle rantr1(10, 20, 30, 50,60);
	rantr1.print_info();
	cout << endl;
	cout << endl;

	RangleTriangle rantr2(10,20,30,50,40);
	rantr2.print_info();
	cout << endl;
	cout << endl;

	IsoscelesTriangle istr1(10,20,50,60);
	istr1.print_info();
	cout << endl;
	cout << endl;

	EquilateralTriangle eqlatr1(30,60);
	eqlatr1.print_info();
	cout << endl;
	cout << endl;

	Quadrangle quadrangle1(10,20,30,40,50,60,70,80);
	quadrangle1.print_info();
	cout << endl;
	cout << endl;

	Rectangl rect1(10,20);
	rect1.print_info();
	cout << endl;
	cout << endl;

	Square square1(10);
	square1.print_info();
	cout << endl;
	cout << endl;

	Parallelogram parall1(20, 30,60,120);
	parall1.print_info();
	cout << endl;
	cout << endl;

	Rhomb rhomb1(30,30,40);
	rhomb1.print_info();
	cout << endl;
	cout << endl;
	return 0;
}

