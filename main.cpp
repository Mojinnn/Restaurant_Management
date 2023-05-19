#include <iostream>
#include <fstream>
#include <ctime>
#include <string.h>
#include "KhachHang.h"
#include "ThanhToan.h"

using namespace std;

//ham Nhap thong tin tung doi tuong
void NhapThongTin (KhachHang &kh, ThanhToan &tt) {
    cout << "-------Nhap Thong Tin Khach Hang-------" << endl;
    kh.setSDT ();
    kh.setTuoi ();
    kh.setChieuCao ();
    tt.setGiaVe (kh);
    tt.setPhi ();
}

//ham Xuat thong tin doi tuong
void XuatThongTin (KhachHang &kh, ThanhToan &tt) {
    cout << "--------------------------------------" << endl;
    cout << "SDT: " << kh.getSDT () << endl;
    cout << "Tuoi: " << kh.getTuoi () << endl;
    cout << "Chieu cao: " << kh.getChieuCao () << endl;
    cout << "Ve: " << tt.getGiaVe () << endl;
    cout << "Phi: " << tt.getPhi () << endl;
    cout << "Thue: " << tt.getThue () << endl;
    cout << "Tong Tien: " << tt.ThanhTien () << endl;
}

string ThoiGian () {
    char *dt= new char[10];
    time_t now = time(0);
    dt = ctime(&now);
    string currentTime(dt);
    return currentTime;
}

//ham ghi file
void GhiFile (KhachHang &kh, ThanhToan &tt) {
    ofstream file;
    file.open("HoaDon.txt", ios::app);        
        file << "----------------------------------------" << endl;
        file << "------ Thoi gian: "<< ThoiGian() << endl;
        file << "SDT: " << kh.getSDT () << endl;
        file << "Tuoi: " << kh.getTuoi () << endl;
        file << "Chieu cao: " << kh.getChieuCao () << endl;
        file << "Ve: " << tt.getGiaVe () << endl;
        file << "Phi: " << tt.getPhi () << endl;
        file << "Thue: " << tt.getThue () << endl;
        file << "Tong Tien: " << tt.ThanhTien () << endl;
        file << endl;
    file.close();
}

//ham main
int main () {
    int soluong;
    KhachHang *kh;
    ThanhToan *tt;

    cout << "Nhap so luong khach hang: ";
    cin >> soluong;

    kh = new KhachHang [soluong];
    tt = new ThanhToan [soluong];

    for (int i = 0; i < soluong; i++) {
        NhapThongTin (kh[i], tt[i]);
    }

    for (int i = 0; i < soluong; i++) {
        XuatThongTin (kh[i], tt[i]);
    }

    for (int i = 0; i < soluong; i++) {
        GhiFile (kh[i], tt[i]);
    }

    delete [] kh;
    delete [] tt;

    return 0;
}