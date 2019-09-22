#include<fstream>
#include<iostream>
#include<iomanip>
#include<string>
#include<math.h>
#include<vector>
#include<algorithm>
using namespace std;

ifstream fin("out.txt");
ofstream fout("out2.txt");
ofstream fout2("sorted_grades.txt");

float to_float(string s,int i){
	int p=0;
	int times=1;
	float num=0;

	cout<<s<<" "<<s.size()<<"<<<<";
		for(int j=s.size()-1; j>=0; j--){
			if(s[j]==' '){
				continue;
			}
			if(s[j]!='.'){		
				num+=(s[j]-'0')*times;
				times*=10; 
				//cout<<num<<" "<<times<<"\t";
				//cout<<s[i]-'0'<<endl;
			}
			else{p=j+1;}
		}
	//cout<<s<<" "<<i<<" "<<num/(pow(10,p))<<endl;
	return float(num/(pow(10,p)));
}


struct score{
	string course;
	float grade;
};

struct GPE{
	int id;
	vector<score> summary;
	float gpe;
};

void sort_them(GPE array[],int sizes){
	bool sorted=true;
	GPE temp;
	int i=0;
	do{	sorted=true;
		for(int j=0; j<sizes; j++){
			if(array[j].gpe<array[j-1].gpe){
				sorted=false;
				array[j-1]=temp;
				array[j-1]=array[j];
				array[j]=temp;
			}
		}
		i++;
	}while(sorted==false);
}

void print_them(GPE array[],int sizes){
	//cout<<"OOOOOOOOOOOOOOOOOOOOOOKKKKKKKKKKKKKKKKKKKKKKKKK\n";
	for(int i=0; i<sizes; i++){
		fout2<<"ID: "<<setw(5)<<array[i].id<<"\t ";
		fout2<<array[i].summary[0].course<<" "<<setw(6)<<fixed<<setprecision(3)<<array[i].summary[0].grade;
		for(int j=1; j<array[i].summary.size(); j++){
			fout2<<setw(8)<<array[i].summary[j].course;
			fout2<<setw(6)<<array[i].summary[j].grade;
		}
		fout2<<setw(14*(6-array[i].summary.size())+10)<<fixed<<setprecision(3)<<array[i].gpe<<"\n";
	}
}

bool checki(GPE A,GPE B){
	return A.gpe>B.gpe;
}

int main(){
	float average=0;
	int countt=0;
	string s;
	float grade;
	string argv;
	int i=0;
	GPE student[7999];
	while(fin>>argv){
		//fout<<i<<" :: ";
		//cout<<argv<<endl;
		if(argv=="[1]:"){
			if(countt!=0){
				fout<<setw(14*(6-countt)+10)<<fixed<<setprecision(3)<<float(average/countt)<<"\n";
				student[i].gpe=float(average/countt);
				i++;
			}
			average=0;
			countt=0;
			fout<<"\n"<<argv;
		}
		else if(argv[1]!='.'&&argv[i]!='.'){
		//	cout<<argv[i]<<endl;
			fout<<setw(8)<<argv;
			//cout<<argv[i]<<endl;
		}	
			student[i].id=i;
			fin>>grade;
			score ss;
			ss.course=argv;
			ss.grade=grade;
			student[i].summary.push_back(ss);
			//cout<<i<<" "<<student[i].summary.back().course<<" "<<student[i].summary.back().grade<<"        "<<student[i].summary.size()<<endl;
		//else if(argv[i][1]<='9'&&argv[i][1]>=0){
		//	cout<<argv[i]<<"\n";
			//float num=to_float(argv[i],i);
			//cout<<num<<"<<<";
			//float num=to_float(argv[i],i);
			//cout<<argv[i]<<" "<<num<<endl;
			fout<<setw(6)<<grade;
			average+=grade;
			countt++;
	}
		fout<<setw(13*(6-countt)+10)<<fixed<<setprecision(3)<<float(average/countt)<<"\n";
		//sort_them(student,i);
		//
		sort(student,student+i,checki);
		cout<<student[2].summary[1].course<<" "<<student[2].summary[1].grade<<endl;
		print_them(student,i);

	return 0;
}
