#include<bits/stdc++.h>
    #include <string>
    #include <windows.h>
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
    void SetConsoleColor(int text_color, int background_color);
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

    void SetConsoleColor(int text_color, int background_color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), text_color | (background_color << 4));
    }

    KH Nhap(KH a) {
//        cin.ignore();
//        cout << "Vui long nhap TEN khach hang vao: ";
//        getline(cin, a.ten);
//        cout << "Vui long nhap TUOI cua khach hang: ";
//        cin >> a.tuoi;
//        cin.ignore();
//        cout << "Vui long nhap GIOI TINH cua khach hang: ";
//        getline(cin, a.gioitinh);
//        cout << "Vui long nhap SDT khach hang: ";
//        cin >> a.SDT;
//        cout << endl;
//        cin.ignore();


        cout << endl;
        cin.ignore();
        cout << "+---------------------------------------------------\n";
        cout << "|"; cout << "Vui long nhap TEN khach hang vao: "; getline(cin, a.ten) ;
        cout << "|"; cout << "Vui long nhap TUOI khach hang vao: "; cin >> a.tuoi;
        cin.ignore();
        cout << "|"; cout << "Vui long nhap GIOI TINH khach hang vao: "; getline(cin, a.gioitinh);
        cout << "|"; cout << "Vui long nhap SDT khach hang: "; cin >> a.SDT;
        cout << "+---------------------------------------------------\n";
        cout << endl;
        cin.ignore();
        return a;
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
        int x;
        deleteHead(sl, x);
        if (x == 1)
            tong += 120;
        else if (x == 2)
            tong += 70;
        else if (x == 3)
            tong += 210;
        else if (x == 4)
            tong += 150;
        else if (x == 5)
            tong += 120;
        else if (x == 6)
            tong += 140;
    }
    return tong;
}

int Tinhtienmonlau(SList sl, int tong, int dem) {
    for (int i = 0; i < dem; i++) {
        int x;
        deleteHead(sl, x);
        if (x == 1)
            tong += 90;
        else if (x == 2)
            tong += 100;
        else if (x == 3)
            tong += 125;
        else if (x == 4)
            tong += 100;
        else if (x == 5)
            tong += 95;
        else if (x == 6)
            tong += 130;
    }
    return tong;
}

int Tinhtienmonnuoc(SList sl, int tong, int dem) {
    for (int i = 0; i < dem; i++) {
        int x;
        deleteHead(sl, x);
        if (x == 1)
            tong += 15;
        else if (x == 2)
            tong += 13;
        else if (x == 3)
            tong += 10;
        else if (x == 4)
            tong += 10;
        else if (x == 5)
            tong += 10;
        else if (x == 6)
            tong += 10;
    }
    return tong;
}

void Tinhtientong(SList sl1, SList sl2, SList sl3, int& tong, int dem1, int dem2, int dem3) {
    tong = 0;

    tong = Tinhtienmonnuong(sl1, tong, dem1);
    tong = Tinhtienmonlau(sl2, tong, dem2);
    tong = Tinhtienmonnuoc(sl3, tong, dem3);
    cout << endl;
    cout << "+------------------------------------------+\n";
    cout << "|"; cout << "\tTong TIEN cua quy khach la: " << tong << "k\n";
    cout << "+------------------------------------------+\n";
    cout << endl;
}


    void Danhsachmonnuong(int A1[], int& dem1) {
        FILE* f;
        f = fopen("anuong.txt", "r");
        if (f != NULL) {
            char c = fgetc(f);
            while (c != EOF) {
                cout << c;
                c = fgetc(f);
            }
            cout << endl;
            fclose(f);
        } else {
            cout << "Khong the mo file anuong.txt" << endl;
            return;
        }

        int i = 0;
        cout << "Nhap mon can chon! Muon dung nhan 0" << endl << endl;

        do {
            cout << "Mon thu " << i + 1 << ": ";
            do {
                cin >> A1[i];
                if (A1[i] < 0 || A1[i] > 6) {
                    cout << "Vui long chon mon tu 1 den 6. Chon 0 de THOAT." << endl;
                    break;
                }
            } while (A1[i] < 0 || A1[i] > 6);

            dem1++;

            if (A1[i] == 0) {
                dem1--;
                break;
            }

            i++;

        } while (i < 20);

        cout << endl;
    }

    void Xuatmonnuong(int A1[], int& dem1) {
        cout << "+-------------------------------------------+\n";
        cout << "|            Danh sach mon NUONG            |\n";
        cout << "+-------------------------------------------+\n";
        bool co_mon_nuong = false;
        for (int i = 0; i < dem1; i++) {
            if (A1[i] == 1){
                cout<<"1. Thit Ba Chi Nuong     120k"<<endl;
                co_mon_nuong = true;
            }
            if (A1[i] == 2){
                cout<<"2. Tom Nuong Muoi Ot     70k"<<endl;
                co_mon_nuong = true;
            }
            if (A1[i] == 3){
                cout<<"3. Thit Bo Nuong Tang    210k"<<endl;
                co_mon_nuong = true;
            }
            if (A1[i] == 4){
                cout<<"4. Thit Bo Nuong Cay     150k"<<endl;
                co_mon_nuong = true;
            }
            if (A1[i] == 5){
                cout<<"5. Muc Nuong             120k"<<endl;
                co_mon_nuong = true;
            }
            if (A1[i] == 6){
                cout<<"6. Suon Nuong Han Quoc   140k"<<endl;
                co_mon_nuong = true;
        }
        }
        if (!co_mon_nuong) {
        cout << "Quy khach chua chon mon nao o menu nay." << endl;
        }
        cout << endl;
    }


void Innuong(int A1[], int& dem1) {
    FILE* f;
    f = fopen("monnuong.txt", "w");
    if (f == NULL) {
        cout << "Khong the mo file de ghi!";
        return;
    }
    fprintf(f, "<<Danh sach mon nuong>>\n");
    for (int i = 0; i < dem1; i++) {
        if (A1[i] == 1)
            fprintf(f, "1. Thit Ba Chi Nuong     120k\n");
        if (A1[i] == 2)
            fprintf(f, "2. Tom Nuong Muoi Ot     70k\n");
        if (A1[i] == 3)
            fprintf(f, "3. Thit Bo Nuong Tang    210k\n");
        if (A1[i] == 4)
            fprintf(f, "4. Thit Bo Nuong Cay     150k\n");
        if (A1[i] == 5)
            fprintf(f, "5. Muc Nuong             120k\n");
        if (A1[i] == 6)
            fprintf(f, "6. Suon Nuong Han Quoc   140k\n");
    }
    fclose(f);
}


    void Danhsachmonlau(int A2[], int& dem2) {
        FILE* f;
        f = fopen("alau.txt", "r");
        if (f != NULL) {
            char c = fgetc(f);
            while (c != EOF) {
                cout << c;
                c = fgetc(f);
            }
            cout << endl;

        } else {
            cout << "Khong the mo file alau.txt" << endl;
            return;
        }

        int i = 0;
        cout << "Nhap mon can chon! Muon dung nhan 0" << endl << endl;

        do {
            cout << "Mon thu " << i + 1 << ": ";
            do {
                cin >> A2[i];
                if (A2[i] < 0 || A2[i] > 6) {
                    cout << "Vui long chon mon tu 1 den 6. Chon 0 de THOAT." << endl;
                    break;
                }
            } while (A2[i] < 0 || A2[i] > 6);

            dem2++;

            if (A2[i] == 0) {
                dem2--;
                break;
            }

            i++;

        } while (i < 20);

        cout << endl;
        fclose(f);
    }

    void Xuatmonlau(int A2[], int dem2) {
        cout << "+-------------------------------------------+\n";
        cout << "|            Danh sach mon LAU              |\n";
        cout << "+-------------------------------------------+\n";
        bool co_mon_lau = false;
        for (int i = 0; i < dem2; i++) {
            if (A2[i] == 1){
                cout<<"1. Lau Thap Cam          90k"<<endl;
                co_mon_lau = true;
            }
            if (A2[i] == 2){
                cout<<"2. Lau Thai Chua Cay     100k"<<endl;
                bool co_mon_lau = false;
            }
            if (A2[i] == 3){
                cout<<"3. Lau Ca Keo            125k"<<endl;
                bool co_mon_lau = false;
            }
            if (A2[i] == 4){
                cout<<"4. Lau Ech               100k"<<endl;
                bool co_mon_lau = false;
            }
            if (A2[i] == 5){
                cout<<"5. Lau Reu Cua           95k"<<endl;
                bool co_mon_lau = false;
            }
            if (A2[i] == 6){
                cout<<"6. Lau Bo                130k"<<endl;
                bool co_mon_lau = false;
            }
        }
        if (!co_mon_lau) {
        cout << "Quy khach chua chon mon nao o menu nay." << endl;
        }
        cout<<endl;
    }

        void Inlau(int A2[], int& dem2) {
            FILE* f;
            f = fopen("monlau.txt", "w");
            if (f == NULL) {
                cout << "Khong the mo file de ghi!";
                return;
            }
            fprintf(f, "<<Danh sach mon lau>>\n");
            for (int i = 0; i < dem2; i++) {
                if (A2[i] == 1)
                    fprintf(f, "1. Lau Thap Cam          90k\n");
                if (A2[i] == 2)
                    fprintf(f, "2. Lau Thai Chua Cay     100k\n");
                if (A2[i] == 3)
                    fprintf(f, "3. Lau Ca Keo            125k\n");
                if (A2[i] == 4)
                    fprintf(f, "4. Lau Ech               100k\n");
                if (A2[i] == 5)
                    fprintf(f, "5. Lau Reu Cua           95k\n");
                if (A2[i] == 6)
                    fprintf(f, "6. Lau Bo                130k\n");
            }
            fclose(f);
        }

    void Danhsachmonnuoc(int A3[], int& dem3) {
        FILE* f;
        f = fopen("anuoc.txt", "r");
        if (f != NULL) {
            char c = fgetc(f);
            while (c != EOF) {
                cout << c;
                c = fgetc(f);
            }
            cout << endl;
        } else {
            cout << "Khong the mo file annuoc.txt" << endl;
            return;
        }

        int i = 0;
        cout << "Nhap mon can chon! Muon dung nhan 0" << endl << endl;

        do {
            cout << "Mon thu " << i + 1 << ": ";
            do {
                cin >> A3[i];
                if (A3[i] < 0 || A3[i] > 6) {
                    cout << "Vui long chon mon tu 1 den 6. Chon 0 de THOAT." << endl;
                    break;
                }
            } while (A3[i] < 0 || A3[i] > 6);

            dem3++;

            if (A3[i] == 0) {
                dem3--;
                break;
            }

            i++;

        } while (i < 20);

        cout << endl;
        fclose(f);
    }

    void Xuatmonnuoc(int A3[], int& dem3) {
    cout << "+-------------------------------------------+\n";
    cout << "|            Danh sach mon NUOC             |\n";
    cout << "+-------------------------------------------+\n";
    bool co_mon_nuoc = false;
    for (int i = 0; i < dem3; i++) {
        if (A3[i] == 1) {
            cout << "1. Bia Tiger              15k" << endl;
            co_mon_nuoc = true;
        }
        if (A3[i] == 2) {
            cout << "2. Bia SaiGon             13k" << endl;
            co_mon_nuoc = true;
        }
        if (A3[i] == 3) {
            cout << "3. Sting                  10k" << endl;
            co_mon_nuoc = true;
        }
        if (A3[i] == 4) {
            cout << "4. 7up                    10k" << endl;
            co_mon_nuoc = true;
        }
        if (A3[i] == 5) {
            cout << "5. Pepsi                  10k" << endl;
            co_mon_nuoc = true;
        }
        if (A3[i] == 6) {
            cout << "6. Nuoc Suoi              10k" << endl;
            co_mon_nuoc = true;
        }
    }
    if (!co_mon_nuoc) {
        cout << "Quy khach chua chon mon nao o menu nay." << endl;
    }
    cout << endl;
}

            void Innuoc(int A3[], int& dem3) {
            FILE* f;
            f = fopen("monnuoc.txt", "w");
            if (f == NULL) {
                cout << "Khong the mo file de ghi!";
                return;
            }
            fprintf(f, "<<Danh sach mon nuoc>>\n");
            for (int i = 0; i < dem3; i++) {
                if (A3[i] == 1)
                    fprintf(f, "1. Bia Tiger             15k\n");
                if (A3[i] == 2)
                    fprintf(f, "2. Bia SaiGon            13k\n");
                if (A3[i] == 3)
                    fprintf(f, "3. Sting                 10k\n");
                if (A3[i] == 4)
                    fprintf(f, "4. 7up                   10k\n");
                if (A3[i] == 5)
                    fprintf(f, "5. Pepsi                 10k\n");
                if (A3[i] == 6)
                    fprintf(f, "6. Nuoc Suoi             10k\n");
            }
            fclose(f);
        }
    void Phanhoi() {
        int sao;
        cout << "Nhap vao danh gia cua ban:";
        cin.ignore();
        char* dg = new char[100];

        if (dg == nullptr) {
            cout << "Khong the cap phat bo nho dong.";
            return;
        }
        gets(dg);

        do {
            cout << "Nhap so sao ban muon danh gia (tu 1 den 5): ";
            cin >> sao;

            if (sao < 1 || sao > 5) {
                cout << "Vui long nhap so sao danh gia tu 1 den 5!" << endl;
            } else {
                break;
            }

        } while (true);

        cout << endl;
        cout << "Danh gia cua Quy Khach: " << dg;
        cout << endl;
        cout << "So sao Quy Khach danh gia cho nha hang: " << sao;
        cout << endl;
        cout << "\t\t\t+-------------------------------------------------------------------------------+\n";
        cout << "\t\t\t|    CAM ON QUY KHACH DA DANH GIA CHO NHA HANG, CHUC QUY KHACH NGON MIENG!      |\n";
        cout << "\t\t\t+-------------------------------------------------------------------------------+\n";

        delete[] dg;
    }

    void Xuat(KH a) {
    const int columnWidth = 15;

        cout << setfill('-') << setw(4 * columnWidth + 3) << "" << endl;

        cout << setfill(' ') << left << setw(columnWidth) << "| Ten"
                << setw(columnWidth) << "| Tuoi"
                << setw(columnWidth) << "| Gioi tinh"
                << setw(columnWidth) << "| SDT" << endl;

        cout << setfill('-') << setw(4 * columnWidth + 3) << "" << endl;

        cout << setfill(' ') << left << setw(columnWidth) << "| " + a.ten
                << setw(columnWidth) << "| " + to_string(a.tuoi)
                << setw(columnWidth) << "| " + a.gioitinh
                << setw(columnWidth) << "| " + a.SDT << endl;

        cout << setfill('-') << setw(4 * columnWidth + 3) << "" << endl;

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
        system("cls");
        cout << "\n	                          \tCHUONG TRINH QUAN LI NHA HANG                      \n";
        cout << "\t	+-----------------------------------------------------------------------------+\n";
        cout << "\t	| [1]. Nhap thong tin khach hang   | [6]. Muc cap nhat mon an cho khach hang  |\n";
        cout << "\t	| [2]. Xuat thong tin khach hang   | [7]. Quy khach vui long xac nhan lai     |\n";
        cout << "\t	| [3]. Danh sach cac mon nuong     | [8]. Tong hoa don du kien cua khach      |\n";
        cout << "\t	| [4]. Danh sach cac mon lau       | [9]. Danh gia cua khach hang             |\n";
        cout << "\t	| [5]. Danh sach cac mon nuoc      | [10]. Ghi file                           |\n";
        cout << "\t        |                               [0]. THOAT                                    |\n";
        cout << "\t	+-----------------------------------------------------------------------------+\n";
        cout << endl;
        cout << "+------------------------------------------+\n";
        cout << "|        Moi ban chon chuc nang:           |\n";
        cout << "+------------------------------------------+\n";
        cout << endl;
        cout << "CHUC NANG: ";
    }

    void Menu(KH a, int A1[], int dem1, int A2[], int dem2, int A3[], int dem3, SList sl1, SList sl2, SList sl3, int tong) {
        int chon, flat = 1;
        bool ok = false;
        while (flat) {
            Goimenu();
            cin >> chon;
            do{
            if(chon < 0 || chon > 9) cout << "Vui long nhap lai lua chon cua Quy Khach!" << endl;
            switch (chon) {
            case 1:
                a = Nhap(a);
                cout << endl;
                ok = true;
                system("pause");
                break;

            case 2:
                if(ok){
                cout << endl;
            cout << "+------------------------------------------+\n";
            cout << "|         Thong tin khach hang la:         |\n";
            cout << "+------------------------------------------+\n";
            cout << endl;
                Xuat(a);
                cout << endl << endl << endl;
                system("pause");
                break;
                }
                else{
                    cout << "Vui long nhap thong tin khac hang!" << endl;
                    cout << endl;
                    system("pause");
                    break;
                }
            case 3:
                if(ok){
                Innuong(A1,dem1);
                Danhsachmonnuong(A1, dem1);
                Xuatmonnuong(A1, dem1);
                system("pause");
                break;
                }
                else{
                    cout << "Vui long nhap thong tin khac hang!" << endl;
                    cout << endl;
                    system("pause");
                    break;
                }
            case 4:
                if(ok){
                Danhsachmonlau(A2, dem2);
                Xuatmonlau(A2, dem2);
                system("pause");
                break;
                }
                else{
                    cout << "Vui long nhap thong tin khac hang!" << endl;
                    cout << endl;
                    system("pause");
                    break;
                }
            case 5:
                if(ok){
                Danhsachmonnuoc(A3, dem3);
                Xuatmonnuoc(A3, dem3);
                system("pause");
                break;
                }
                else{
                    cout << "Vui long nhap thong tin khac hang!" << endl;
                    cout << endl;
                    system("pause");
                    break;
                }
            case 6:
                if(ok){
                    int n;
                    cout << "\t\t\t+-------------------------------------------+\n";
                    cout << "\t\t\t|     Chon [1]: la thay doi mon NUONG       |\n";
                    cout << "\t\t\t|     Chon [2]: la thay doi mon LAU         |\n";
                    cout << "\t\t\t|     Chon [3]: la thay doi mon NUOC        |\n";
                    cout << "\t\t\t|     Chon [0] de THOAT.                    |\n";
                    cout << "\t\t\t+-------------------------------------------+\n";
                    cout << endl;
                    do {
                    cout << "MUC GOI Y MON AN" << endl;
                    cout << "Moi quy khach chon muc mon an: ";
                    cin >> n;
                    if (n == 1){
                    Innuong(A1,dem1);
                    Danhsachmonnuong(A1, dem1);
                    Xuatmonnuong(A1, dem1);
                    system("pause");
                    break;
                    }
                    else if (n == 2){
                    Danhsachmonlau(A2, dem2);
                    Xuatmonlau(A2, dem2);
                    system("pause");
                    break;
                    }
                    else if(n == 3){
                    Danhsachmonnuoc(A3, dem3);
                    Xuatmonnuoc(A3, dem3);
                    system("pause");
                    break;
                    }
                    else
                        cout << "Quy khach da chon THOAT chuong trinh.";
                        cout << endl;
                        system("pause");

                } while (n != 0);
                break;
                }

                else{
                    cout << "Vui long nhap thong tin khac hang!" << endl;
                    cout << endl;
                    system("pause");
                    break;
                }
            case 7:
                if(ok){
                cout << "\t\t\t+-------------------------------------------+\n";
                cout << "\t\t\t|     Danh sach cac mon vua order           |\n";
                cout << "\t\t\t+-------------------------------------------+\n";
                cout << endl;
                Xuatmonnuong(A1, dem1);
                Xuatmonlau(A2, dem2);
                Xuatmonnuoc(A3, dem3);
                cout << "<<Neu quy khach muon them mon vui long oder lai menu mon do>>" << endl;
                cout << endl;
                system("pause");
                break;
                }
                else{
                    cout << "Vui long nhap thong tin khach hang!" << endl;
                    cout << endl;
                    system("pause");
                    break;
                }
            case 8:
                if(ok){
                createSList(sl1, A1, dem1);
                createSList(sl2, A2, dem2);
                createSList(sl3, A3, dem3);
                Tinhtientong(sl1, sl2, sl3, tong, dem1, dem2, dem3);
                cout << endl << endl << endl;
                system("pause");
                break;
                }
                else{
                    cout << "Vui long nhap thong tin khac hang!" << endl;
                    cout << endl;
                    system("pause");
                    break;
                }
            case 9:
                if(ok){
                Phanhoi();
                system("pause");
                break;
                }
                else{
                    cout << "Vui long nhap thong tin khac hang!" << endl;
                    cout << endl;
                    system("pause");
                    break;
                }
            case 10:
                if(ok){
                Innuong(A1, dem1);
                Inlau(A2, dem2);
                Innuoc(A3, dem3);
                cout << endl;
                cout << "\t\t\t+--------------------------------------------------------+\n";
                cout << "\t\t\t|     Da ghi file cac mon theo yeu cau cua quy khach     |\n";
                cout << "\t\t\t+--------------------------------------------------------+\n";
                cout << endl;
                system("pause");
                break;
                }
                else{
                    cout << "Vui long nhap thong tin khac hang!" << endl;
                    cout << endl;
                    system("pause");
                    break;
                }
            case 0:
                cout << "\t\t\t+----------------------------------------------------------+\n";
                cout << "\t\t\t|     CAM ON QUY KHACH, RAT HAN HANH PHUC VU QUY KHACH.    |\n";
                cout << "\t\t\t+----------------------------------------------------------+\n";
                cout << endl;
                flat = 0;
                system("pause");
                break;
                        }
                    }while(chon < 0 && chon > 9);
                }
            }


    int main() {
        SetConsoleColor(FOREGROUND_BLUE | FOREGROUND_INTENSITY, BACKGROUND_BLUE);
        KH a;
        int A1[20], dem1 = 0;
        int A2[20], dem2 = 0;
        int A3[20], dem3 = 0;
        SList sl1, sl2, sl3;
        int tong = 0;

        Menu(a, A1, dem1, A2, dem2, A3, dem3, sl1, sl2, sl3, tong);
        return 0;
    }

