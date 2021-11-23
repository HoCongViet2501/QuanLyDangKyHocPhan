
#include "DoHoa.h"
#include <bits/stdc++.h>
using namespace std;

struct HocPhan{
     int maHocPhan;
     string tenHocPhan;
     string tiet;
     string thu;
     int soTC;
     string giangvien;
     int soluongSV;
};
struct SinhVien{
     int maSV;
     string tenSV;
     string tenlop;
     int namsinh;
     string gioitinh;
     int maHocPhan;
};
struct Node{
    HocPhan infoHP;
    SinhVien infoSV;
    Node* pNext;
};
struct List{
    Node *pFirst,*pLast;
};

void initNode(List &lst);
void docFileHP(List &lst);
void docFileSV(List &lst);
void insertLastHP(List &lst,HocPhan hp);
void insertLastHP(List &lst,SinhVien sv);
void firstGui(void);
void AdminGui();
void sinhvienGui();
void showDSHocPhan(List lst);
void choice();
void choiceSV();
void Heading(void);
void dkhp(List lst);
void suaHocPhan(List lst);
void xoaHP(List lst);
void searchMa(List lst);
void exportDSHP(List lst);
void exportDSSVDKHP(List lst);
void xuatDSHPdaDky(List lst);
void importFile(List lst);
void ThemLopHP(HocPhan &hp);
void thoiKhoaBieuSV(List lst);
void showDSSVtheoMaHP(List lst);

int main(){
	List lst;
	resizeConsole(970,600);
	initNode(lst);
   firstGui();
   return 0;
}

void initNode(List &lst){
	lst.pFirst=lst.pLast=NULL;
}

Node* createNodeHP(HocPhan hp){
    Node* node= new Node;
    node->infoHP=hp;
    node->pNext=NULL;
    return node;
}
void insertLastHP(List &lst,HocPhan hp){
   Node *node=createNodeHP(hp);
   if(lst.pFirst==NULL){
    lst.pFirst=node;
    lst.pLast=node;
   }else{
      lst.pLast->pNext=node;
      lst.pLast=node;
   }
}
void docFileHP(List &lst){
   ifstream fp("HocPhan.csv");
   if(!fp.is_open()){
    cout << "khong mo duoc file";
    return;
   }
   HocPhan hp;
   while(fp.eof()==false){

      fp >> hp.maHocPhan;
      fp.ignore();
      getline(fp,hp.tenHocPhan,',');
      getline(fp,hp.tiet,',');
      getline(fp,hp.thu,',');
      fp >> hp.soTC;
      fp.ignore();
      getline(fp,hp.giangvien,',');
      fp >> hp.soluongSV;
      fp.ignore();
      insertLastHP(lst,hp);
   }
   fp.close();
}

void delay(unsigned int mseconds)
{
	clock_t goal = mseconds + clock();
	while (goal > clock());
}
Node* createNodeSV(SinhVien sv){
    Node* node= new Node;
    node->infoSV=sv;
    node->pNext=NULL;
    return node;
}
void insertLastSV(List &lst,SinhVien sv){
   Node *node=createNodeSV(sv);
   if(lst.pFirst==NULL){
    lst.pFirst=node;
    lst.pLast=node;
   }else{
      lst.pLast->pNext=node;
      lst.pLast=node;
   }
}
void docFileSV(List &lst){
   ifstream fp("sv.csv");
   if(!fp.is_open()){
    cout << "khong mo duoc file";
    return;
   }

   while(fp.eof()==false){
      SinhVien sv;
      fp >> sv.maSV;
      fp.ignore();
      getline(fp,sv.tenSV,',');
      getline(fp,sv.tenlop,',');
      fp >> sv.namsinh;
      fp.ignore();
      getline(fp,sv.gioitinh,',');
      fp>>sv.maHocPhan;
      fp.ignore();
      insertLastSV(lst,sv);
   }
   fp.close();

}
void showDSHocPhan(List lst){
	cout << "Ma hoc phan | Ten hoc phan  | Tiet | Thu | So tin chi | Giang vien | So luong sinh vien \n";
	for(Node *p=lst.pFirst;p!=NULL;p=p->pNext){
		cout <<p->infoHP.maHocPhan<<" | "<< p->infoHP.tenHocPhan<<" | "<< p->infoHP.tiet<<" | "<< p->infoHP.thu<<" | "<< p->infoHP.soTC<<" | "<< p->infoHP.giangvien<<" | "<< p->infoHP.soluongSV<< endl;

	}
}
void showDssv(List lst){
	cout << " Ma sinh vien|Ten sinh vien|Ten lop| Nam sinh | Gioi tinh |Hoc phan dang ky|\n";
     docFileSV(lst);
	for(Node *p=lst.pFirst;p!=NULL;p=p->pNext){
		cout  <<" | "<<p->infoSV.maSV<<" | "<< p->infoSV.tenSV<<" | "<< p->infoSV.tenlop<<" | "<< p->infoSV.namsinh<<" | "<< p->infoSV.gioitinh<<" | "<< p->infoSV.maHocPhan <<endl;
	}
}

void ThemLopHP(HocPhan &hp) {
	cin.ignore();
	ofstream temp;
	temp.open("HocPhan.csv",ios::app);
	cout << "Nhap Ma hoc phan : ";
	cin >> hp.maHocPhan;
	temp << hp.maHocPhan<<", ";

    fflush(stdin);
	cout << "\nNhap Ten hoc phan:";
	getline(cin,hp.tenHocPhan);
	temp <<hp.tenHocPhan<<", ";

	fflush(stdin);
	cout << "\nNhap so tiet:";
	getline(cin,hp.tiet);
	temp <<hp.tiet<<",";

	fflush(stdin);
	cout << "\nNhap thu :";
    getline(cin,hp.thu);
    temp <<hp.thu<<",";

	fflush(stdin);
	cout << "\nNhap so tin chi : ";
	cin>>hp.soTC;
	temp <<hp.soTC<<",";

	fflush(stdin);
	cout << "\nNhap ten giang vien : ";
      getline(cin,hp.giangvien);
      temp <<hp.giangvien<<", ";

	fflush(stdin);
	cout << "\nNhap so luong sinh vien: ";
	cin >> hp.soluongSV;
	temp <<hp.soluongSV<<"\n";
	temp.close();


}
void searchMa(List lst){
	int  mhp;
	cout << "nhap Ma lop hoc phan can Tim Kiem : ";
	cin >> mhp;
    cout << "\n Ma hoc phan | Ten hoc phan  | Tiet | Thu | So tin chi | Giang vien | So luong sinh vien \n";
	for (Node* p = lst.pFirst; p != NULL; p = p->pNext) {
		if (p->infoHP.maHocPhan == mhp) {
	        cout <<" | "<<p->infoHP.maHocPhan<<" | "<< p->infoHP.tenHocPhan<<" | "<< p->infoHP.tiet<<" | "<< p->infoHP.thu<<" | "<< p->infoHP.soTC<<" | "<< p->infoHP.giangvien<<" | "<< p->infoHP.soluongSV<< endl;
		}
	}
}

void xoaHP(){
	int rollnum,roll1,count=0;
	string line,word;
	vector<string> row;
	HocPhan hp;
	ifstream iFile;
	iFile.open("HocPhan.csv",ios::in);
	if(!iFile){
		cout << "Khong the mo file\n";
		return;
	}
	ofstream oFile;
	oFile.open("HPtemp.csv",ios::out);
	cout << "Nhap ma hoc phan muon xoa: ";
	cin >> rollnum;
	while (!iFile.eof()) {

        row.clear();
        getline(iFile, line);
        stringstream s(line);

        while (getline(s, word,',')) {
            row.push_back(word);
        }

        int row_size = row.size();
        roll1 =stoi(row[0]);
	    if (roll1 != rollnum) {
	        if (!iFile.eof()) {
	            for (int i = 0; i < row_size - 1; i++) {
	                oFile << row[i] << ", ";
	            }
	            oFile << row[row_size - 1] << "\n";
	            }
	        }
	        else {
	            count = 1;
	        }
	        if (iFile.eof())
	            break;
	    }
	    if(count==1){
	    	cout << "Xoa thanh cong!\n";
		}else cout << "Xoa khong thanh cong! Vui long xem lai!\n";

		iFile.close();
		oFile.close();

		remove("HocPhan.csv");
		rename("HPTemp.csv","HocPhan.csv");

}
void suaHocPhan(){
    int rollnum,roll1,count=0;
	string line,word;
	vector<string> row;
	string tenHocPhan;
     string tiet,thu,giangvien;
     int soTC,soluongSV,index;
	ifstream iFile;
	iFile.open("HocPhan.csv",ios::in);
	if(!iFile){
		cout << "Khong the mo file\n";
		return;
	}
	ofstream oFile;
	oFile.open("HPtemp.csv",ios::out);
	cout << "Nhap ma hoc phan ban muon sua: ";
	cin >> rollnum;
	char sub;
	cout << "Nhap thong tin ban muon sua(t(tenHocPhan)/e(tiet)/u(thu)/g(giang vien)/c(sotc)/o(soluongsv):";
	cin >> sub;
    stringstream convert;
    if(sub=='t'){
        index=1;
        cout<< "Nhap ten hoc phan moi: ";
        cin.ignore();
         getline(cin,tenHocPhan,'\n');
        convert << tenHocPhan;
    }else if(sub=='e'){
        index=2;
        cout<< "Nhap tiet moi: ";
        cin.ignore();
         getline(cin,tiet,'\n');
        convert << tiet;
    }else if(sub=='u'){
        index=3;
        cout<< "Nhap thu moi: ";
        cin.ignore();
         getline(cin,thu,'\n');
        convert << thu;
    }else if(sub=='c'){
        index=4;
        cout<< "Nhap so tin chi moi: "; cin >> soTC;
        convert << soTC;
    }else if(sub=='g'){
        index=5;
        cout<< "Nhap giang vien moi: ";
        cin.ignore();
         getline(cin,giangvien,'\n');
        convert << giangvien;
    }else if(sub=='o'){
        index=6;
        cout<< "Nhap so luong sinh vien moi: "; cin >> soluongSV;
        convert << soluongSV;
    }else{
        cout << "Ban da nhap sai lua chon!";
        suaHocPhan();
    }
    while (!iFile.eof()) {
        row.clear();
        getline(iFile, line);
        stringstream s(line);

        while (getline(s, word,',')) {
            row.push_back(word);
        }
        roll1 = stoi(row[0]);
        int row_size = row.size();
        if (roll1 == rollnum) {
            count = 1;
            row[index] = convert.str();

            if (!iFile.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    oFile << row[i] << ", ";
                }
                oFile << row[row_size - 1] << "\n";
            }
        }
        else {
            if (!iFile.eof()) {
                for (int i = 0; i < row_size - 1; i++) {
                    oFile << row[i] << ", ";
                }
                oFile << row[row_size - 1] << "\n";
            }
        }
        if (iFile.eof())
            break;
    }
    if (count == 0)
        cout << "Sua khong thanh cong!Vui long xem lai\n";
    else if(count==1){
        cout << "Sua thanh cong!Du lieu moi da duoc luu xuong file";
    }
    iFile.close();
    oFile.close();
    remove("HocPhan.csv");
    rename("HPtemp.csv","HocPhan.csv");
}
void importFile(List lst){
    string file;
    ifstream fp;
    HocPhan hp;
    cout << "Nhap duong dan file(.csv) ban muon import:";
    cin >> file;
    fp.open(file);
    if(fp.is_open()==false){
        cout << "Khong nhan duoc file!Hay xem lai duong dan file!";
        importFile(lst);
    }
    while(fp.eof()==false){

      fp >> hp.maHocPhan;
      fp.ignore();
      getline(fp,hp.tenHocPhan,',');
      getline(fp,hp.tiet,',');
      getline(fp,hp.thu,',');
      fp >> hp.soTC;
      fp.ignore();
      getline(fp,hp.giangvien,',');
      fp >> hp.soluongSV;
      fp.ignore();
      insertLastHP(lst,hp);
   }
   ofstream oFile;
   oFile.open("HocPhan.csv",ios::app);
    oFile << hp.maHocPhan << ",";
    oFile << hp.tenHocPhan << ",";
    oFile << hp.tiet << ",";
    oFile << hp.thu << ",";
    oFile << hp.soTC << ",";
    oFile << hp.giangvien << ",";
    oFile << hp.soluongSV << endl;
   fp.close();
   oFile.close();
   cout << "Import thanh cong!Da duoc luu xuong file!";
}
void exportDSHP(List lst){
    ofstream oFile;
   oFile.open("HocPhanExport.csv",ios::out);
   for(Node *p=lst.pFirst;p!=NULL;p=p->pNext){
    oFile << p->infoHP.maHocPhan << ",";
    oFile << p->infoHP.tenHocPhan << ",";
    oFile << p->infoHP.tiet << ",";
    oFile << p->infoHP.thu << ",";
    oFile << p->infoHP.soTC << ",";
    oFile << p->infoHP.giangvien << ",";
    oFile << p->infoHP.soluongSV << endl;
   }
   cout << "Xuat file thanh cong!Ten file la HocPhanExport.csv ,Hay kiem tra trong thu muc";
   oFile.close();
}
void exportDSSVDKHP(List lst){
    docFileSV(lst);
      ofstream fp;
   fp.open("SinhviendaDKHP.csv",ios::out);
   for(Node* p = lst.pFirst; p != NULL; p = p->pNext){
                fp << p->infoSV.maSV << ",";
                fp << p->infoSV.tenSV << ",";
                fp << p->infoSV.tenlop << ",";
                fp << p->infoSV.namsinh << ",";
                fp << p->infoSV.gioitinh << ",";
                fp << p->infoSV.maHocPhan << "\n";

            }
   cout << "Xuat file thanh cong!Ten file la SinhviendaDKHP.csv ,Hay kiem tra trong thu muc";
   fp.close();
}
void swap(SinhVien &sv1,SinhVien &sv2){
    SinhVien temp=sv1;
    sv1=sv2;
    sv2=temp;
}
void showDSSVtheoMaHP(List lst){
    if(lst.pFirst!=NULL){
        Node *p1=lst.pFirst;
        while(p1!=NULL){
            Node *p2=p1->pNext;
            while(p2!=NULL){
               if(p1->infoSV.maHocPhan>p2->infoSV.maHocPhan){
                swap(p1->infoSV,p2->infoSV);

                }
                p2=p2->pNext;
            }
            p1=p1->pNext;
        }
    }
    else cout<<  "list rong";
    cout << " Ma hoc phan dang ky|Ma sinh vien|Ten sinh vien|Ten lop| Nam sinh | Gioi tinh |\n";

	for(Node *p=lst.pFirst;p!=NULL;p=p->pNext){
		cout <<" | "<< p->infoSV.maHocPhan  <<" | "<<p->infoSV.maSV<<" | "<< p->infoSV.tenSV<<" | "<< p->infoSV.tenlop<<" | "<< p->infoSV.namsinh<<" | "<< p->infoSV.gioitinh<<" | " <<endl;
	}

}

void dkhp(List lst){
        int masv,mhp;
        docFileSV(lst);

        cout << "Nhap ma sinh vien cua ban:";
        cin >> masv;
        ofstream fp;
        fp.open("sv.csv",ios::app);
        for(Node* p = lst.pFirst; p != NULL; p = p->pNext){
            if(p->infoSV.maSV==masv){
            cout << "Nhap ma hoc phan ban muon dang ky:";
            cin >> mhp;
              for(Node *p1=lst.pFirst;p1!=NULL;p1=p1->pNext){
                if(mhp==p1->infoHP.maHocPhan ){
                fp << p->infoSV.maSV << ",";
                fp << p->infoSV.tenSV << ",";
                fp << p->infoSV.tenlop << ",";
                fp << p->infoSV.namsinh << ",";
                fp << p->infoSV.gioitinh << ",";
                fp << mhp << "\n";

                }
              }

            }
        }
        cout << "Dang ky hoc phan  thanh cong!Da duoc luu xuong file!\n";
        fp.close();
}

void xuatDSHPdaDky(List lst){
        int masv,mhp;
        docFileHP(lst);
        docFileSV(lst);

        cout << "Nhap ma sinh vien cua ban:";
        cin >> masv;
        cout << " Danh sach hoc phan da dang ky!\n\n";
        cout << " Ma hoc phan | Ten hoc phan  | Tiet | Thu | So tin chi | Giang vien \n";
         cout << "-------------------------------------------------------------------\n";
        for(Node* p = lst.pFirst; p != NULL; p = p->pNext){
            if(p->infoSV.maSV==masv){
                mhp=p->infoSV.maHocPhan;
          for(Node *p1=lst.pFirst;p1!=NULL;p1=p1->pNext){
          if( mhp==p1->infoHP.maHocPhan){

            cout <<" | "<<p1->infoHP.maHocPhan<<" | "<< p1->infoHP.tenHocPhan<<" | "<< p1->infoHP.tiet<<" | "<< p1->infoHP.thu<<" | "<< p1->infoHP.soTC<<" | "<< p1->infoHP.giangvien<< endl;

                }
              }
            }
        }


}
void thoiKhoaBieuSV(List lst){
       int masv;
        docFileSV(lst);
        docFileHP(lst);
        cout << "Nhap ma sinh vien cua ban:";
        cin >> masv;
        cout << "\t Thoi khoa bieu!\n\n";
        cout << "|    Ten hoc phan     |   Tiet    |   Thu   |   Giang vien | \n";
        cout << "----------------------------------------------------------------\n";
        for(Node *p=lst.pFirst;p!=NULL;p=p->pNext){
            if(p->infoSV.maSV==masv){
          for(Node *p1=lst.pFirst;p1!=NULL;p1=p1->pNext){
          if( p->infoSV.maHocPhan==p1->infoHP.maHocPhan){

            cout <<" | "<< p1->infoHP.tenHocPhan<<" | "<< p1->infoHP.tiet<<" | "<< p1->infoHP.thu<<" | "<< p1->infoHP.giangvien<< endl;

           }
         }
        }
        }
}

void Heading(void)
{
	cout << "\n";
	for (int rep = 1; rep <= 130; rep++) cout << char(219); cout << endl;
    cout << "\t\t\t          \5\5\5====================================================\5\5\5\n";
    cout << "\t\t\t\t               Chuong trinh Quan Ly Dang Ky Hoc Phan\n";
    cout << "\t\t\t\t\t\t          \5\5\5\5\5\5\5\5\5\5\5\5\n";
	for (int rep = 1; rep <= 130; rep++) cout << char(219); cout << endl;
}
void choice(){
	int option;
	cout << "\n\n   Nhap lua chon: \n";
	cout << "\t1.Quay lai menu\n";
	cout << "\t2.Ket thuc\n";
	cout << "\tHay nhap lua chon:";
	cin >> option;
	switch(option){
		case 1:
			system("cls");
			adminGoto: AdminGui();
			break;
		case 2:
			exit(1);
			break;
	}
}
void choiceSV(){
	int option;
	cout << "\n\n   Nhap lua chon: \n";
	cout << "\t1.Quay lai menu\n";
	cout << "\t2.Ket thuc\n";
	cout << "\tHay nhap lua chon:";
	cin >> option;
	switch(option){
		case 1:
			system("cls");
            sinhvienGui();
			break;
		case 2:
			exit(1);
			break;
	}
}
void AdminGui(){
	int option;
	HocPhan hp;
	List lst;
	initNode(lst);
	Heading();
	cout << "\n\n\t\t\t\t\t\t      ";
	for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " ADMIN "; for (int rep = 1; rep <= 7; rep++) cout << char(219);
	cout << "\n\n\n    Danh sach lua chon: \n";
	cout << "      1.Them hoc phan \n";
	cout << "      2.Xoa hoc phan\n";
	cout << "      3.Sua hoc phan\n";
	cout << "      4.Tim kiem hoc phan theo ma hoc phan\n";
	cout << "      5.Import danh sach hoc phan\n";
	cout << "      6.Export danh sach hoc phan\n";
	cout << "      7.Hien thi danh sach sinh vien theo ma lop hoc phan\n";
	cout << "      8.Show danh sach hoc phan\n";
	cout << "      9.Xuat danh sach sinh vien da dang ky hoc phan ra file csv\n";
	cout << "      10.Quay lai\n";
	cout << "      11.thoat\n\n";
	cout << "      Nhap lua chon: \n";
	cin >> option;
	switch(option){
		case 1:
			system("cls");
			Heading();
            int option;
            cout << "Chon so hoc phan ma ban muon them: ";
            cin >> option;
            for(int i=1;i<=option;i++){
                cout << "\n\t\t=========Nhap hoc phan thu " << i << "========="<< endl;
                ThemLopHP(hp);
            }
            delay(600);
            cout << "\t\t=========Them thanh cong\n";
            choice();
			break;
		case 2:
			system("cls");
		    Heading();
		    docFileHP(lst);
		    showDSHocPhan(lst);
		    cout << endl;
		    xoaHP();
		    delay(800);
		    choice();
		    break;
		case 3:
			system("cls");
            Heading();
            docFileHP(lst);
            showDSHocPhan(lst);
            cout << endl;
            suaHocPhan();
            choice();
		    break;
		case 4:
			system("cls");
			Heading();
			docFileHP(lst);
		    searchMa(lst);
		    choice();
		    break;
		case 5:
			system("cls");
		    Heading();
		    importFile(lst);
		    delay(900);
		    docFileHP(lst);
		    cout << endl;
		    showDSHocPhan(lst);
		    choice();
		    break;
		case 6:
			system("cls");
            Heading();
            docFileHP(lst);
            delay(600);
            exportDSHP(lst);
            choice();
		    break;
		case 7:
			system("cls");
			docFileSV(lst);
            Heading();
            showDSSVtheoMaHP(lst);
            choice();
		    break;
		case 8:
			system("cls");
			docFileHP(lst);
            Heading();
			showDSHocPhan(lst);
		    choice();
		    break;
		case 9:
			system("cls");
			Heading();
			delay(800);
			exportDSSVDKHP(lst);
			choice();
		    break;
		case 10:
			system("cls");
		    firstGuiGoto: firstGui();
		    break;
        case 11:
            exit(1);
            break;
	}

}
void sinhvienGui(){
	int option;
	List lst;
	Heading();
	initNode(lst);
	cout << "\n\n\t\t\t\t\t\t      ";
	for (int rep = 1; rep <= 7; rep++) cout << char(219); cout << " Sinh Vien "; for (int rep = 1; rep <= 7; rep++) cout << char(219);
	cout << "\n\n\n    Danh sach lua chon: \n";
	cout << "     1.Dang ky hoc phan\n";
	cout << "     2.Hien thi danh sach hoc phan da dang ky\n";
	cout << "     3.Hien thi thoi khoa bieu da dang ky trong hoc ky\n";
	cout << "     4.Quay lai\n";
	cout << "     5.Thoat\n";
	cout << " ==>Hay nhap lua chon: ";
	cin >> option;
	switch(option){
		case 1:
			system("cls");
			Heading();
			docFileHP(lst);
			showDSHocPhan(lst);
			cout <<endl;
			dkhp(lst);
            choiceSV();
			break;
		case 2:
			system("cls");
			Heading();
			xuatDSHPdaDky(lst);
			choiceSV();
			break;
		case 3:
			system("cls");
			Heading();
            thoiKhoaBieuSV(lst);
			choiceSV();
			break;
		case 4:
            system("cls");
			firtguigoto: firstGui();
			break;
        case 5:
            system("cls");
            exit(1);
            break;
	}

}
void firstGui(void){
	system("COLOR 9F");
	Heading();
    int option;
    cout << " Ban la: " << endl;
    cout << " 1.Admin \n";
    cout << " 2.Sinh Vien \n";
    cout << " Nhap lua chon: ";
    cin >> option;
    switch(option){
        case 1:
        	system("cls");
        	AdminGui();
		    break;
		case 2:
		    system("cls");
		    sinhvienGui();
			break;
    }

}

