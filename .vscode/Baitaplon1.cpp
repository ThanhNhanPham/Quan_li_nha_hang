#include<bits/stdc++.h>
using namespace std;

struct SNode {
    int Info;
    SNode* Next;
};

struct SList {
    SNode* Head;
    SNode* Tail;
};
struct KH {
    string ten;
    int tuoi;
    string gioitinh;
    string SDT;
};

// Khai bao cac ham
SNode* createSNode(int x);
void showSNode(SNode* p);
void initSList(SList& sl);
int isEmpty(SList sl);
int insertHead(SList& sl, SNode* p);
void showSList(SList sl);
int deleteHead(SList& sl, int& x);
void createSList(SList& sl, int A[], int dem);
int Tinhtienmonnuong(SList sl, int tong, int dem);
int Tinhtienmonlau(SList sl, int tong, int dem);
int Tinhtienmonnuoc(SList sl, int tong, int dem);
void Tinhtientong(SList sl1, SList sl2, SList sl3, int& tong, int dem1, int dem2, int dem3);
void Danhsachmonnuong(int A1[], int& dem1);
void Xuatmonnuong(int A1[], int &dem1);
void Innuong(int A1[], int &dem1);
void Danhsachmonlau(int A2[], int& dem2);
void Xuatmonlau(int A2[], int dem2);
void Inlau(int A2[], int &dem2);
void Danhsachmonnuoc(int A3[], int& dem3);
void Xuatmonnuoc(int A3[], int &dem3);
void Innuoc(int A3[], int &dem3);
KH Nhap(KH a);
void xuat(KH a);

void Phanhoi();
void Inbill();
void Goimenu();


KH Nhap(KH a) {
    cin.ignore();
    cout << "Vui long nhap ten khach hang vao: ";
    getline(cin, a.ten);
    cout << "Vui long nhap tuoi cua khach hang: ";
    cin >> a.tuoi;
    cin.ignore();
    cout << "Vui long nhap gioi tinh cua khach hang: ";
    getline(cin, a.gioitinh);
    cout << "Vui long nhap SDT: ";
    cin >> a.SDT;
    cout << endl;
    cin.ignore();
    return a;
}
void xuat(KH a) {

	cout<<"-Ten :"<<a.ten;
	cout<<"-Tuoi:"<<a.tuoi;
	cout<<"-Gioi tinh:"<<a.gioitinh;
	cout<<"-SDT:"<<a.SDT;
}
SNode* createSNode(int x) {
    SNode* p = new SNode;


    if (p == NULL) {
        cout << "Khong the cap phat nut moi.";
        return NULL;
    }
    p->Info = x;
    p->Next = NULL;
    return p;
}

void showSNode(SNode* p) {
    cout << p->Info;
}

void initSList(SList& sl) {
    sl.Head = NULL;
    sl.Tail = NULL;
}

int isEmpty(SList sl) {
    return sl.Head == NULL;
}

int insertHead(SList& sl, SNode* p) {
    if (p == NULL)
        return 0;
    if (isEmpty(sl) == 1) {
        sl.Head = p;
        sl.Tail = p;
    }
    else {
        p->Next = sl.Head;
        sl.Head = p;
    }
    return 1;
}

void showSList(SList sl) {
    if (isEmpty(sl)) {
        cout << "Danh sach rong.";
        return;
    }
    SNode* p = sl.Head;
    while (p != NULL) {
        showSNode(p);
        p = p->Next;
    }
}

int deleteHead(SList& sl, int& x) {
    if (isEmpty(sl) == 1) {
        return 0;
    }
    SNode* p = sl.Head;
    sl.Head = sl.Head->Next;
    if (sl.Head == NULL) {
        sl.Tail = NULL;
    }
    x = p->Info;
    delete p;
    return 1;
}

void createSList(SList& sl, int A[], int dem) {
    initSList(sl);
    for (int i = 0; i < dem; i++) {
        int x = A[i];
        SNode* p = createSNode(x);
        insertHead(sl, p);
    }
}

int Tinhtienmonnuong(SList sl, int tong, int dem) {
    for (int i = 0; i < dem; i++) {
        int x = 0;
        deleteHead(sl, x);
        if (x == 1)
            x = 120;
        if (x == 2)
            x = 70;
        if (x == 3)
            x = 210;
        if (x == 4)
            x = 150;
        if (x == 5)
            x = 120;
        if (x == 6)
            x = 140;
        tong = tong + x;
    }
    return tong;
}

int Tinhtienmonlau(SList sl, int tong, int dem) {
    for (int i = 0; i < dem; i++) {
        int x;
        deleteHead(sl, x);
        if (x == 1)
            x = 90;
        if (x == 2)
            x = 100;
        if (x == 3)
            x = 125;
        if (x == 4)
            x = 100;
        if (x == 5)
            x = 95;
        if (x == 6)
            x = 130;
        tong = tong + x;
    }
    return tong;
}

int Tinhtienmonnuoc(SList sl, int tong, int dem) {
    for (int i = 0; i < dem; i++) {
        int x;
        deleteHead(sl, x);
        if (x == 1)
            x = 15;
        if (x == 2)
            x = 13;
        if (x == 3)
            x = 10;
        if (x == 4)
            x = 10;
        if (x == 5)
            x = 10;
        if (x == 6)
            x = 10;
        tong = tong + x;
    }
    return tong;
}

void Tinhtientong(SList sl1, SList sl2, SList sl3, int& tong, int dem1, int dem2, int dem3) {
    tong = Tinhtienmonnuong(sl1, tong, dem1) + Tinhtienmonlau(sl2, tong, dem2) + Tinhtienmonnuoc(sl3, tong, dem3);
    cout << "Tong tien du kien la: " << tong<<"k";
}

void Danhsachmonnuong(int A1[], int& dem1) {
    FILE* f;
    f = fopen("anuong.txt", "r");
    if (f != NULL) {
        char c = fgetc(f);
        while (c != EOF) {
            cout<<("%c", c);
            c = fgetc(f);
        }
    }
    cout << endl;
    int i;
    cout << "Nhap mon can chon! Muon dung nhan 0"<<endl;
    for (int i = 0; i < 20; i++) {
        cout << "Mon thu " << i + 1<<":";
        cin >> A1[i];
        dem1++;
        if (A1[i] == 0) {
            dem1--;
            break;
        }
    }
    cout << endl;
    fclose(f);
}

void Xuatmonnuong(int A1[], int& dem1) {
    cout << "\n==Danh sach cac mon NUONG da chon==\n";
    for (int i = 0; i < dem1; i++) {
        if (A1[i] == 1)
            cout<<"1. Thit Ba Chi Nuong     120k"<<endl;
        if (A1[i] == 2)
            cout<<"2. Tom Nuong Muoi Ot     70k"<<endl;
        if (A1[i] == 3)
            cout<<"3. Thit Bo Nuong Tang    210k"<<endl;
        if (A1[i] == 4)
            cout<<"4. Thit Bo Nuong Cay     150k"<<endl;
        if (A1[i] == 5)
            cout<<"5. Muc Nuong             120k"<<endl;
        if (A1[i] == 6)
            cout<<"6. Suon Nuong Han Quoc   140k"<<endl;
    }
    cout << endl;
}

void Innuong(int A1[], int& dem1) {

   FILE* f;
    f = fopen("monnuong.txt", "w");
    cout<< "<<Danh sach mon nuong>>"<<endl;
    if (f == NULL) {
        cout << "Khong the mo file de ghi!";
        return;
    }
    for (int i = 0; i < dem1; i++) {
        if (A1[i] == 1)
            cout<< "1. Thit Ba Chi Nuong     120k"<<endl;
        if (A1[i] == 2)
            cout<< "2. Tom Nuong Muoi Ot     70k"<<endl;
        if (A1[i] == 3)
            cout<< "3. Thit Bo Nuong Tang    210k"<<endl;
        if (A1[i] == 4)
            cout<< "4. Thit Bo Nuong Cay     150k"<<endl;
        if (A1[i] == 5)
            cout<< "5. Muc Nuong             120k"<<endl;
        if (A1[i] == 6)
            cout<< "6. Suon Nuong Han Quoc   140k"<<endl;
    }
    fclose(f);
}

void Danhsachmonlau(int A2[], int& dem2) {
    FILE* f;
    f = fopen("alau.txt", "r");
    if (f != NULL) {
        char c = fgetc(f);
        while (c != EOF) {
            cout<<("%c", c);
            c = fgetc(f);
        }
    }
   cout<<endl;
    int i;
    cout<<"Nhap mon can chon! Muon dung nhan 0"<<endl;
    for (int i = 0; i < 20; i++) {
        cout<<"Mon thu "<< i + 1<<":";
        cin>> A2[i];
        dem2++;
        if (A2[i] == 0) {
            dem2--;
            break;
        }
    }
    cout<<endl;
    fclose(f);
}

void Xuatmonlau(int A2[], int dem2) {
    cout<<"==Danh sach cac mon LAU da chon=="<<endl;
    for (int i = 0; i < dem2; i++) {
        if (A2[i] == 1)
            cout<<"1. Lau Thap Cam          90k"<<endl;
        if (A2[i] == 2)
            cout<<"2. Lau Thai Chua Cay     100k"<<endl;
        if (A2[i] == 3)
            cout<<"3. Lau Ca Keo            125k"<<endl;
        if (A2[i] == 4)
            cout<<"4. Lau Ech               100k"<<endl;
        if (A2[i] == 5)
            cout<<"5. Lau Reu Cua           95k"<<endl;
        if (A2[i] == 6)
            cout<<"6. Lau Bo                130k"<<endl;
    }
    cout<<endl;
}

void Inlau(int A2[], int& dem2) {
    FILE* f;
    f = fopen("monlau.txt", "w");
    cout<< "<<Danh sach mon lau>>"<<endl;
    if (f == NULL) {
        cout<<"Khong the mo file de ghi!";
        return;
    }
    for (int i = 0; i < dem2; i++) {
        if (A2[i] == 1)
            cout<< "1. Lau Thap Cam          90k"<<endl;
        if (A2[i] == 2)
            cout<< "2. Lau Thai Chua Cay     100k"<<endl;
        if (A2[i] == 3)
            cout<< "3. Lau Ca Keo            125k"<<endl;
        if (A2[i] == 4)
            cout<< "4. Lau Ech               100k"<<endl;
        if (A2[i] == 5)
            cout<< "5. Lau Reu Cua           95k"<<endl;
        if (A2[i] == 6)
            cout<< "6. Lau Bo                130k"<<endl;
    }
    fclose(f);
}

void Danhsachmonnuoc(int A3[], int& dem3) {
    FILE* f;
    f = fopen("anuoc.txt", "r");
    if (f != NULL) {
        char c = fgetc(f);
        while (c != EOF) {
            cout<<("%c", c);
            c = fgetc(f);
        }
    }
    cout << endl;
    int i;
    cout << "Nhap mon can chon! Muon dung nhan 0"<<endl;
    for (int i = 0; i < 20; i++) {
        cout << "Mon thu " << i + 1<<":";
        cin >> A3[i];
        dem3++;
        if (A3[i] == 0) {
            dem3--;
            break;
        }
    }
    cout << endl;
    fclose(f);
}

void Xuatmonnuoc(int A3[], int& dem3) {
    cout << "\n==Danh sach cac mon NUOC da chon==\n";
    for (int i = 0; i < dem3; i++) {
        if (A3[i] == 1)
            cout << "1. Bia Tiger              15k"<<endl;
        if (A3[i] == 2)
            cout << "2. Bia SaiGon             13k"<<endl;
        if (A3[i] == 3)
            cout << "3. Sting                  10k"<<endl;
        if (A3[i] == 4)
            cout << " 7up                      10k"<<endl;
        if (A3[i] == 5)
            cout << "5. Pepsi                  10k"<<endl;
        if (A3[i] == 6)
            cout << "6. Nuoc Suoi              10k"<<endl;
    }
    cout << endl;
}

void Innuoc(int A3[], int& dem3) {
    FILE* f;
    f = fopen("monnuoc.txt", "w");
    cout<< "<<Danh sach mon nuoc>>"<<endl;
    
    if (f == NULL) {
        cout<<"Khong the mo file de ghi!";
        return;
    }
    for (int i = 0; i < dem3; i++) {
        if (A3[i] == 1)
            cout<< "1. Bia Tiger             15k"<<endl;
        if (A3[i] == 2)
            cout<< "2. Bia SaiGon            13k"<<endl;
        if (A3[i] == 3)
            cout<< "3. Sting                 10k"<<endl;
        if (A3[i] == 4)
            cout<< "4. 7up                   10k"<<endl;
        if (A3[i] == 5)
            cout<< "5. Pepsi                 10k"<<endl;
        if (A3[i] == 6)
            cout<< "6. Nuoc Suoi             10k"<<endl;
    }
    fclose(f);
}

void Phanhoi() {
    int sao;
    cout << "Nhap vao danh gia cua ban:";
    cin.ignore();
 char* dg = new char[1000];

    if (dg == NULL) {
        cout << "Khong the cap phat bo nho dong.";
        return;
    }
    gets(dg);
    cout << "Nhap so sao ban muon danh gia: ";
    cin >> sao;
    cout<< sao;
    FILE* P;
    P = fopen("phanhoi.txt", "w");
       fputs("Phan hoi cua khach la: ", P);
    fputs(dg, P);
    fputs("\n", P);
    fputs("So sao danh gia: ", P);
    cout<<(P, sao);
    fclose(P);
    delete[] dg;
}

void Xuat(KH a) {
    cout << "- Ten :" << a.ten;
    cout << "- Tuoi:" << a.tuoi;
    cout << "- Gioi tinh:" << a.gioitinh;
    cout << "- SDT:" << a.SDT;
}

void Inbill() {
    char ch;
    FILE* file1, * file2, * file3, * file4, * file5, * file6;
    file1 = fopen("thongtin.txt", "r");
    file2 = fopen("monnuong.txt", "r");
    file3 = fopen("monlau.txt", "r");
    file4 = fopen("monnuoc.txt", "r");
    file5 = fopen("tinhtong.txt", "r");
    file6 = fopen("BILL CUA QUY KHACH.txt", "w");
    fputs("<<<<<<<< Nha Hang Restaurant >>>>>>>>\n", file6);
    while ((ch = fgetc(file1)) != EOF) {
        fputc(ch, file6);
    }
    while ((ch = fgetc(file2)) != EOF) {
        fputc(ch, file6);
    }
    while ((ch = fgetc(file3)) != EOF) {
        fputc(ch, file6);
    }
    while ((ch = fgetc(file4)) != EOF) {
        fputc(ch, file6);
    }
    while ((ch = fgetc(file5)) != EOF) {
        fputc(ch, file6);
    }
    fputs("\n", file6);
    fputs("---------Cam on quy khach------------", file6);
    fclose(file2);
    fclose(file3);
    fclose(file4);
    fclose(file5);
    fclose(file6);
}

void Goimenu() {
    cout << "+-----------------------------------+\n";
    cout << "|                                   |\n";
    cout << "|             MENU                  |\n";
    cout << "|                                   |\n";
    cout << "| 1. Nhap thong tin khach hang.     |\n";
    cout << "| 2. Xuat thong tin khach hang.     |\n";
    cout << "| 3. Danh sach cac mon nuong.       |\n";
    cout << "| 4. Danh sach cac mon lau.         |\n";
    cout << "| 5. Danh sach cac mon nuoc.        |\n";
    cout << "| 6. Muc goi y cho khach hang.      |\n";
    cout << "| 7. Quy khach vui long xac nhan lai|\n";
    cout << "|     mon an cua khach.             |\n";
    cout << "| 8. Tong hoa don du kien cua khach |\n";
    cout << "| 9. Danh gia cua khach hang.       |\n";
    cout << "| 10. Chon 0 de thoat.              |\n";
    cout << "|                                   |\n";
    cout << "+-----------------------------------+\n";
    cout << "Moi ban chon chuc nang: ";
}

void Menu(KH a, int A1[], int dem1, int A2[], int dem2, int A3[], int dem3, SList sl1, SList sl2, SList sl3, int tong) {
    int chon, flat = 1;
    while (flat) {
        Goimenu();
        cin >> chon;
        switch (chon) {
        case 1:
            a = Nhap(a);
            cout << endl;
            break;
        case 2:
            cout << "--Thong tin khach hang la" << endl;
            Xuat(a);
            cout << endl << endl << endl;
            break;
        case 3:
        	Innuong(A1,dem1);
            Danhsachmonnuong(A1, dem1);
            Xuatmonnuong(A1, dem1);
            break;
        case 4:
            Danhsachmonlau(A2, dem2);
            Xuatmonlau(A2, dem2);
            break;
        case 5:
            Danhsachmonnuoc(A3, dem3);
            Xuatmonnuoc(A3, dem3);
            break;
        case 6:
            int n;
            cout << "chon 1 la muc goi y mon nuong" << endl;
            cout << "chon 2 la muc goi y mon lau" << endl;
            cout << "chon 0 de thoat" << endl;
            do {
                cout << "MUC GOI Y MON AN" << endl;
                cout << "Moi quy khach chon muc mon an" << endl;
                cin >> n;
                if (n == 1)
                                cout << "MUC GOI Y MON AN" << endl;

                else if (n == 2)
                                    cout << "MUC GOI Y MON AN" << endl;

                else
                    cout << "vui long nhap lai muc" << endl;

            } while (n != 0);
            break;
        case 7:
            cout << "---------Danh sach cac mon vua oder------------" << endl;

            Xuatmonnuong(A1, dem1);
            Xuatmonlau(A2, dem2);
            Xuatmonnuoc(A3, dem3);
            cout << "<<Neu quy khach muon doi mon vui long oder lai menu mon do>>" << endl;
            break;
        case 8:
            createSList(sl1, A1, dem1);
            createSList(sl2, A2, dem2);
            createSList(sl3, A3, dem3);
            Tinhtientong(sl1, sl2, sl3, tong, dem1, dem2, dem3);
            cout << endl << endl << endl;
            break;
        case 9:
            Phanhoi();
            break;
        case 0:
//           Infile(a);
            Innuong(A1, dem1);
            Inlau(A2, dem2);
            Innuoc(A3, dem3);
            cout << "----------------Bill cua quy khach da duoc luu v";


    cout << "----------------Bill cua quy khach da duoc luu vao FILE---------------------\n ";
    cout << "----------------------Cam on quy khach------------------------------";
    flat = 0;
    break;
    	}
    }
}

int main() {
    KH a;
    int A1[20], dem1 = 0;
    int A2[20], dem2 = 0;
    int A3[20], dem3 = 0;
    SList sl1, sl2, sl3;
    int tong = 0;

    Menu(a, A1, dem1, A2, dem2, A3, dem3, sl1, sl2, sl3, tong);
    return 0;
}

