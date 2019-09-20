#include <iostream>
using namespace std;

class Vec3d{
private:
	double x,y,z;

public:
	Vec3d(double x=0, double y=0, double z=0) : x(x), y(y), z(z){}
	friend double dot(Vec3d a, Vec3d b) {
		return (a.x*b.x+a.y*b.y+a.z*b.z);
	}
	friend Vec3d operator + (Vec3d a, Vec3d b) {
		return Vec3d (a.x+b.x,a.y+b.y,a.z+b.z);
	}
	Vec3d operator - (Vec3d b) const {
		return Vec3d(x-b.x,y-b.y,z-b.z);
	}
	Vec3d operator - () const {
		return Vec3d(-1*x,-1*y,-1*z);
	}
	friend ostream& operator << (ostream& s, const Vec3d a){
	return s << '(' << a.x << ',' << a.y << ',' << a.z << ')';
	}
};

int main(){
	const Vec3d a(1.0, 2.5, 3.2);
	const Vec3d b(2.0, -1.5, 0.5);
	//dot product

	double d = dot(a,b);
	Vec3d c=a+b; //binary operator use a friend
	Vec3d f=a-b; //use a member function
	Vec3d e=-a; //unary operator
	Vec3d g; //0,0,0
	cout << e << endl;
}
