
#include <iostream>
#include <string>

class Shape {
public:
	virtual void Scale(float scaleFactor) = 0;
	virtual void ShowInfo() = 0;
	virtual std::string GetName() = 0;
};

class Shape2D : public Shape {
protected:
	float area;
public:
	virtual float GetArea() = 0;
	virtual bool operator>(Shape2D& other) = 0;
	virtual bool operator<(Shape2D& other) = 0;
	virtual bool operator==(Shape2D& other) = 0;
	virtual void CalculateArea() = 0;
};

class Shape3D : public Shape {
protected:
	float volume;
public:
	virtual float GetVolume() = 0;
	virtual bool operator>(Shape3D& other) = 0;
	virtual bool operator<(Shape3D& other) = 0;
	virtual bool operator==(Shape3D& other) = 0;
	virtual void CalculateVolume() = 0;
};

class Square :public Shape2D {
private:
	float side;
public:
	Square(float s) :side(s) {} //Constructor

	float GetArea() override { return area; }
	void Scale(float scaleFactor) override { area = area * scaleFactor; }
	void ShowInfo() override { std::cout << "Square with side: " << side << std::endl; }
	std::string GetName() override { return "Square"; }
	bool operator>(Shape2D& other) override { return area > other.GetArea(); }
	bool operator<(Shape2D& other) override { return area < other.GetArea(); }
	bool operator==(Shape2D& other) override { return area == other.GetArea(); }
	void CalculateArea() override { area = side * side; }
};

class Triangle : public Shape2D {
private:
	float base;
	float height;
public:
	Triangle(float b, float h) : base(b), height(h) {} // Constructor

	float GetArea() override { return area; }
	void Scale(float scaleFactor) override { area = area * scaleFactor; }
	void ShowInfo() override { std::cout << "Triangle with base: " << base << " and height: " << height << std::endl; }
	std::string GetName() override { return "Triangle"; }
	bool operator>(Shape2D& other) override { return area > other.GetArea(); }
	bool operator<(Shape2D& other) override { return area < other.GetArea(); }
	bool operator==(Shape2D& other) override { return area == other.GetArea(); }
	void CalculateArea() override { area = 0.5 * base * height; }
};

class Circle : public Shape2D {
private:
	float radius;
public:
	Circle(float r) : radius(r) {} // Constructor

	float GetArea() override { return area; }
	void Scale(float scaleFactor) override { area = area * scaleFactor; }
	void ShowInfo() override { std::cout << "Circle with radius: " << radius << std::endl; }
	std::string GetName() override { return "Circle"; }
	bool operator>(Shape2D& other) override { return area > other.GetArea(); }
	bool operator<(Shape2D& other) override { return area < other.GetArea(); }
	bool operator==(Shape2D& other) override { return area == other.GetArea(); }
	void CalculateArea() override { area = 3.141592 * radius * radius; }
};

class TriangularPyramid : public Shape3D {
private:
	float height;
	Triangle baseTriangle;
public:
	TriangularPyramid(float h, float base, float triangleHeight) : height(h), baseTriangle(base, triangleHeight) {} // Constructor

	float GetVolume() override { return volume; }
	void Scale(float scaleFactor) override { volume = volume * scaleFactor; }
	std::string GetName() override { return "TriangularPyramid"; }
	bool operator>(Shape3D& other) override { return volume > other.GetVolume(); }
	bool operator<(Shape3D& other) override { return volume < other.GetVolume(); }
	bool operator==(Shape3D& other) override { return volume == other.GetVolume(); }
	void CalculateVolume() override { volume = (1.0 / 3.0) * baseTriangle.GetArea() * height; }
};

class Cylinder : public Shape3D {
private:
	float height;
	Circle baseCircle;
public:
	Cylinder(float h, float r) : height(h), baseCircle(r) {} // Constructor

	float GetVolume() override { return volume; }
	void Scale(float scaleFactor) override { volume = volume * scaleFactor; }
	std::string GetName() override { return "Cylinder"; }
	bool operator>(Shape3D& other) override { return volume > other.GetVolume(); }
	bool operator<(Shape3D& other) override { return volume < other.GetVolume(); }
	bool operator==(Shape3D& other) override { return volume == other.GetVolume(); }
	void CalculateVolume() override { volume = baseCircle.GetArea() * height; }
};

class Sphere : public Shape3D {
private:
	float radius;
public:
	Sphere(float r) : radius(r) {} // Constructor

	float GetVolume() override { return volume; }
	void Scale(float scaleFactor) override { volume = volume * scaleFactor; }
	std::string GetName() override { return "Sphere"; }
	bool operator>(Shape3D& other) override { return volume > other.GetVolume(); }
	bool operator<(Shape3D& other) override { return volume < other.GetVolume(); }
	bool operator==(Shape3D& other) override { return volume == other.GetVolume(); }
	void CalculateVolume() override { volume = (4.0 / 3.0) * 3.141592 * radius * radius * radius; }
};

int main() {
	Square square(3);
	square.CalculateArea();
	square.ShowInfo();
	std::cout << "Area:" << square.GetArea() << std::endl;

	Triangle triangle(2, 6);
	triangle.CalculateArea();
	triangle.ShowInfo();
	std::cout << "Area:" << triangle.GetArea() << std::endl;

	Circle circle(5);
	circle.CalculateArea();
	circle.ShowInfo();
	std::cout << "Area:" << circle.GetArea() << std::endl;

	TriangularPyramid pyramid(6, 5, 4);
	pyramid.CalculateVolume();
	std::cout << "Volume of TriangularPyramid: " << pyramid.GetVolume() << std::endl;

	Cylinder cylinder(7, 2);
	cylinder.CalculateVolume();
	std::cout << "Volume of Cylinder: " << cylinder.GetVolume() << std::endl;

	Sphere sphere(4);
	sphere.CalculateVolume();
	std::cout << "Volume of Sphere: " << sphere.GetVolume() << std::endl;

	return 0;
}

