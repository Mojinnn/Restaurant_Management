#include <iostream>
#include "ThanhToan.h"
#include "KhachHang.cpp"

using namespace std;


void ThanhToan::setThueVAT () {
    thueVAT = (KhachHang::getGia())*(10/100);
}

void ThanhToan::setPhi () {
    cout << "Phi (neu co): ";
    cin >> phi;
}

long ThanhToan::getPhi () {
    return phi;
}

long ThanhToan::getThueVAT () {
    return thueVAT;
}

long ThanhToan::ThanhTien () {
    return (KhachHang::getGia() + phi + thueVAT);
}
