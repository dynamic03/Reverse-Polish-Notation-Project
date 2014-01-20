#include <iostream>
#include <fstream>
#include<string>
#include<vector>
#include<math.h>

using namespace std;
string number;
vector<double> numberStack;

void calculate(char oprt)
{
	double first,second;
	if(oprt=='+')
	{
		second=numberStack.back();
		numberStack.pop_back();
		first=numberStack.back();
		numberStack.pop_back();
		numberStack.push_back(first+second);
	}
	if(oprt=='-')
	{
		second=numberStack.back();
		numberStack.pop_back();
		first=numberStack.back();
		numberStack.pop_back();
		numberStack.push_back(first-second);
	}
	if(oprt=='*')
	{
		second=numberStack.back();
		numberStack.pop_back();
		first=numberStack.back();
		numberStack.pop_back();
		numberStack.push_back(first*second);
	}
	if(oprt=='/')
	{
		second=numberStack.back();
		numberStack.pop_back();
		first=numberStack.back();
		numberStack.pop_back();
		numberStack.push_back(first/second);
	}
	if(oprt=='^')
	{
		second=numberStack.back();
		numberStack.pop_back();
		first=numberStack.back();
		numberStack.pop_back();
		numberStack.push_back(pow(first,second));
	}
	if(oprt=='%')
	{
		second=numberStack.back();
		numberStack.pop_back();
		first=numberStack.back();
		numberStack.pop_back();
		numberStack.push_back(fmodf(first,second));
	}
}

bool interpret(string container)
{
	int size,index;
	size=container.size();
	if(size==0) return false;////if the input file is empty, then return false.
	for(int i=0;i<size;i++)
	{

		if(!isdigit(container[i])&&container[i]!='+'&&container[i]!='-'&&container[i]!='*'&&container[i]!='/'&&container[i]!='%'&&container[i]!='^'&&container[i]!='.'&&container[i]!=' '&&container[i]!='p' && container[i]!='e') 
			return false;
		if(isdigit(container[i]))
			number.push_back(container[i]);
		if(container[i]=='.' && size>1)//when encouter a dot, there are many conditions are required to be considered, we need to consider what the char is before and after the dot
		{

			if((i==0&& isdigit(container[i+1])) 
				||(i==size-1 && isdigit(container[i-1])) ||((i==1 && isdigit(container[i-1])&& (isdigit(container[i+1])||(container[i+1]=='+')||(container[i+1]=='-')||(container[i+1]=='*')
				||(container[i+1]=='/')||(container[i+1]=='%')||(container[i+1]=='p')||(container[i+1]=='^')||(container[i+1]==' ')) )

				|| (i==1 && isdigit(container[i+1])&&(container[0]==' '||isdigit(container[0]))))   ||((i==size-2 && isdigit(container[i+1])&& (isdigit(container[i-1])||(container[i-1]=='+')||(container[i-1]=='-')||(container[i-1]=='*')
				||(container[i-1]=='/')||(container[i-1]=='%')||(container[i-1]=='w')||(container[i-1]=='^')||(container[i-1]==' ')))

				||(i==size-2 && isdigit(container[i-1])&& (isdigit(container[i+1])||(container[i+1]=='+')||(container[i+1]=='-')||(container[i+1]=='*')
				||(container[i+1]=='/')||(container[i+1]=='%')||(container[i+1]=='p')||(container[i+1]=='^')||(container[i+1]==' ')))) 

				|| ((i>1 && i<size-2 && isdigit(container[i+1])&& (isdigit(container[i-1])||(container[i-1]=='+')||(container[i-1]=='-')||(container[i-1]=='*')
				||(container[i-1]=='/')||(container[i-1]=='%')||(container[i-1]=='w')||(container[i-1]=='^')||(container[i-1]==' ')))

				||(i>1 && i<size-2&& isdigit(container[i-1])|| (isdigit(container[i+1])||(container[i+1]=='+')||(container[i+1]=='-')||(container[i+1]=='*')
				||(container[i+1]=='/')||(container[i+1]=='%')||(container[i+1]=='p')||(container[i+1]=='^')||(container[i+1]==' '))))) 
				number.push_back(container[i]);
			else return false;
			if(i==0&&!isdigit(container[i+1])) return false;
			if(i>0&&i<size-1)
			{
				if(!isdigit(container[i-1]))
					if(!isdigit(container[i+1])) return false;
				if(!isdigit(container[i+1]))
					if(!isdigit(container[i-1])) return false;
			}
			if(i==size-1&&!isdigit(container[i-1]))   return false;

		}
		if(size==1&&container[0]=='.') return false;//if the line only contains a dot and 

		///////////////////////////////scientific notation:extra credit////////////////////////////////
		if(container[i]=='e' && size>1)
		{

			if((i==size-1 && isdigit(container[i-1])) ||((i==1 && isdigit(container[i-1])&& (isdigit(container[i+1])||(container[i+1]=='+')||(container[i+1]=='-')||(container[i+1]=='*')
				||(container[i+1]=='/')||(container[i+1]=='%')||(container[i+1]=='p')||(container[i+1]=='^')||(container[i+1]==' ')) )

				|| (i==1 && isdigit(container[i+1])&&(container[0]==' '||isdigit(container[0]))))   ||((i==size-2 && isdigit(container[i+1])&& (isdigit(container[i-1])||(container[i-1]=='+')||(container[i-1]=='-')||(container[i-1]=='*')
				||(container[i-1]=='/')||(container[i-1]=='%')||(container[i-1]=='w')||(container[i-1]=='^')||(container[i-1]==' ')))

				||(i==size-2 && isdigit(container[i-1])&& (isdigit(container[i+1])||(container[i+1]=='+')||(container[i+1]=='-')||(container[i+1]=='*')
				||(container[i+1]=='/')||(container[i+1]=='%')||(container[i+1]=='p')||(container[i+1]=='^')||(container[i+1]==' ')))) 
				///////////////////
				|| ((i>1 && i<size-2 && isdigit(container[i+1])&& (isdigit(container[i-1])||(container[i-1]=='+')||(container[i-1]=='-')||(container[i-1]=='*')
				||(container[i-1]=='/')||(container[i-1]=='%')||(container[i-1]=='w')||(container[i-1]=='^')||(container[i-1]==' ')))

				||(i>1 && i<size-2&& isdigit(container[i-1])|| (isdigit(container[i+1])||(container[i+1]=='+')||(container[i+1]=='-')||(container[i+1]=='*')
				||(container[i+1]=='/')||(container[i+1]=='%')||(container[i+1]=='p')||(container[i+1]=='^')||(container[i+1]==' '))))) 
				number.push_back(container[i]);
			else return false;
			if(i==0 && isdigit(container[i+1])) return false;
			if(i>=1 && i<size) if(!isdigit(container[i-1])) return false;	
		}
		if(size==1 && container[0]=='e')  return false;


		if(container[i]=='+' || container[i]=='-' ||container[i]=='*'||container[i]=='/' ||container[i]=='%'||container[i]=='^' || container[i]==' ' )
		{
			if(container[i]!=' ')
			{
				if(!number.empty())//convert char into double
				{
					int f;
					bool ff=false;
					for(int i=0;i<number.size();i++)						
					{
						if(number[i]=='e') 
						{
						f=i;
						ff=true;
						break;
						}
					}
					if(ff==true)
					{
						for(int i=f;i<number.size();i++)
							if(number[i]=='.') return false;
						if(number[number.size()-1]=='e') return false;
					}	
					numberStack.push_back(atof(number.c_str()));//push the number into vector, when encounter the operator, pop two numbers and then calculate and then push the result back.
					number.clear();
				}				

				if(numberStack.size()<2) return false;
				else calculate(container[i]);	
			}

			else
			{

				if(!number.empty())
				{
					int f;
					bool ff=false;
					for(int i=0;i<number.size();i++)						
					{
						if(number[i]=='e') //when there is a e, the number after e must be Integer, so just check after e, whether there is a dot
						{
						f=i;
						ff=true;
						break;
						}
					}
					if(ff==true)
					{
						for(int i=f;i<number.size();i++)
							if(number[i]=='.' ) return false;
						if(number[number.size()-1]=='e') return false;
					}					
					numberStack.push_back(atof(number.c_str()));
					number.clear();
				}		
			}
		}

		if(container[i]=='p')//check whether the following are 'o' and 'w'
		{
			if (i+2<size)
			{
				if(container[i+1]=='o'&&container[i+2]=='w' ) 
				{
					if(number.size()!=0)
					{
						int f;
						bool ff=false;

						for(int i=0;i<number.size();i++)						
						{
							if(number[i]=='e') 
							{
							f=i;
							ff=true;
							break;
							}

						}
						if(ff==true)
						{
							for(int i=f;i<number.size();i++)
								if(number[i]=='.' ) return false;
							if(number[number.size()-1]=='e') return false;
						}
						
						numberStack.push_back(atof(number.c_str()));
						number.clear();			    
					}
					if(numberStack.size()<2) return false;
					else calculate('^');
					i=i+2;

				}
				else return false;
			}
			else return false;
		}	
	}
	if(number.size()!=0) 
	{
		int f;
		bool ff=false;

		for(int i=0;i<number.size();i++)						
		{
			if(number[i]=='e') 
			{f=i;
			ff=true;
			break;
			}


		}
		if(ff==true)
		{
			for(int i=f;i<number.size();i++)
				if(number[i]=='.' ) return false;
			if(number[number.size()-1]=='e') return false;
		}

		numberStack.push_back(atof(number.c_str()));
	}
	if(numberStack.size()!=1) return false;
	else return true;
}

int main()
{
	string location;
	cout<<"Please input the location of the file(such as 'E:\\input.txt')"<<endl;
	cout<<"If the input file and the .cpp are under the same path,"<<endl<<"just input the file name.(such as 'input.txt')"<<endl;
	cin>>location;
	cout<<endl;
	ifstream infile(location,ios::in);
	if(infile.fail())
	{
		cout<<"Error! Cannot open the file."<<endl;
		return 0;
	}
	ifstream infileconsole(location,ios::in);
	string container;
	bool result;
	cout<<"Sample Input:"<<endl;
	while(getline(infileconsole,container))
	{
		cout<<container<<endl;
		container.empty();
	}
	cout<<endl;
	cout<<"Sample Output:"<<endl;

	while(getline(infile,container))
	{

		result=interpret(container);
		if(result==true) 
		{
			cout<<container<<":   ";
			cout<<numberStack.back()<<endl;
		}
		else 
		{
			if(container=="") cout<<"The empty line is   ";//when read the empty line
			else cout<<container<<":   ";
			cout<<"SYNTAX ERROR"<<endl;
		}
		number.clear();
		numberStack.clear();
		container.empty();
	}
	infile.close();
	infileconsole.close();
	return 1;
}