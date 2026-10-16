#ifndef BANGLUONG_H
#define BANGLUONG_H
#include <string>
#include "NhanVien.h"
#include "ChucDanh.h"
#include "ChamCong.h"
using namespace std;

// [Chương 2] Bảng lương tháng của 1 nhân viên.
//   luongCoBan = lương hợp đồng * soNgayCong / 26
//   tienTangCa = giờ tăng ca * (lương hợp đồng / 26 / 8) * 1.5
//   thucNhan   = luongCoBan + phuCap + tienTangCa - (bhxh + bhyt + bhtn) - thueTNCN
// [Chương 4] tinhLuong() gọi nv.tinhPhuCapQuanLy() là hàm ảo -> phụ cấp khác nhau theo loại nhân viên.
class BangLuong {
private:
    string maBL, maNV;
    int thang, nam, soNgayCong;
    double luongCoBan, phuCap, tienTangCa;
    double bhxh, bhyt, bhtn, thueTNCN, thucNhan;

    double tinhThueTNCN(double thuNhapChiuThue) const;   // biểu thuế lũy tiến từng phần

public:
    BangLuong();
    BangLuong(const string& maBL, const string& maNV, int thang, int nam);

    string getMaNV() const;
    int getThang() const;
    int getNam() const;
    int getSoNgayCong() const;
    double getThucNhan() const;

    void tinhLuong(const NhanVien& nv, const ChucDanh& cd, const ChamCong dsCC[], int soCC);
    void inPhieuLuong() const;
};

#endif
