#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Person
{
  private:
  	string Ten;
  	int Tuoi;
  public:
  Person()
  {
  };
  Person(string _Ten,int _Tuoi)
  {
  	Ten=_Ten;
  	Tuoi=_Tuoi;
  };	
  void setTen(string _Ten)
  {
  	Ten=_Ten;
  }
  void setTuoi(int _Tuoi)
  {
  	Tuoi=_Tuoi;
  }
  string getTen()
  {
  	return Ten;
  }
  int getTuoi()
  {
  	return Tuoi;
  }
	void nhapPerson()
	{
		cin.ignore();
		cout<<"nhap ten: ";
		getline(cin,Ten);
		cout<<"nhap tuoi: ";
		cin>>Tuoi;
	}
};
class Student:public Person
{
	private:
		float Toan;
		float Hoa;
		float Ly;
	public:
	Student()
	{
	};	
	Student(string _Ten,int _Tuoi,float _Toan,float _Hoa,float _Ly):Person(_Ten,_Tuoi)
	{
		Toan=_Toan;
		Hoa=_Hoa;
		Ly=_Ly;
	}
	void setToan(float _Toan)
	{
		Toan=_Toan;
	}
	void setHoa(float _Hoa)
	{
		Hoa=_Hoa;
	}
	void setLy(float _Ly)
	{
		Ly=_Ly;
	}
	float getToan()
	{
		return Toan;
	}
	float getHoa()
	{
		return Hoa;
	}
	float getLy()
	{
		return Ly;
	}
	void nhapDiem()
	{
		cout<<"diem toan: ";
		cin>>Toan;
		cout<<"diem hoa: ";
		cin>>Hoa;
		cout<<"diem ly: ";
		cin>>Ly;
	}
	float diemTb()
	{
		return (Toan+Hoa+Ly)/3;
	}
};
class Teacher: Person
{
	private:
		vector<Student> danhsach;
		Person P;
		public:
			Teacher()
			{
				
			};
			Teacher(string _Ten,int _Tuoi,vector<Student> ds):Person(_Ten,_Tuoi)
			{
				
				danhsach=ds;
			}
			vector<Student> getdanhsach()
			{
				return danhsach;
			}
			void setdanhsach(vector<Student>ds)
			{
				danhsach=ds;
			}
			Student diemcaonhat()
			{
				Student s=danhsach[0];
				for(int i=1;i<danhsach.size();i++)
				{
					if(s.diemTb()<danhsach[i].diemTb())
					{
						s=danhsach[i];
					}
					
				}
				return s;
			}
			
};
int main()
{  
    Person A;
    Student B;
	int n;
	cout<<"nhap so luong sinh vien: ";
	cin>>n;
	 vector<Student> danhsach;
	for(int i=0;i<n;i++)
	{   string Ten;
	    int Tuoi;
	    float Toan,Hoa,Ly;
		cout<<"sinh vien thu "<<i+1<<endl;
		A.nhapPerson();
		B.nhapDiem();
		danhsach.push_back(Student(Ten, Tuoi,Toan,Ly,Hoa));
		cout<<"diem trung binh: "<<B.diemTb()<<endl;
	}
	string Ten;
	int Tuoi;
	cin.ignore();
	cout<<"nhap ten giao vien: ";
	cin>>Ten;
	cout<<"tuoi: ";
	cin>>Tuoi;
	Teacher tc= Teacher(Ten,Tuoi,danhsach);
	cout<<"sinh vien co diem trung binh cao nhat: ";
	cout<<"ten: "<<tc.diemcaonhat().getTen();
	cout<<"tuoi: "<<tc.diemcaonhat().getTuoi();
	
}















