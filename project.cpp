#include <iostream>
#include <string>
#include <conio.h>
#include <locale>

using namespace std;

class Staff
{

protected:
    string StaffID;
    string Fullname;
    string Dateofbirth;
    string Address;

public:
    void setSTAFFID(string s) { s = StaffID; }
    string getSTAFFID() { return StaffID; }
    void setFULLNAME(string s) { s = Fullname; }
    string getFULLNAME() { return Fullname; }
    void setDATEOFBIRTH(string s) { s = Dateofbirth; }
    string getDATEOFBIRTH() { return Dateofbirth; }
    void setADDRESS(string s) { s = Address; }
    string getADDRESS() { return Address; }
    Staff(string _StaffID = "0", string _Fullname = "fullname", string _Dateofbirth = "0", string _Address = "address")
    {
        StaffID = _StaffID;
        Fullname = _Fullname;
        Dateofbirth = _Dateofbirth;
        Address = _Address;
    }

    Staff(const Staff &s)
    {
        StaffID = s.StaffID;
        Fullname = s.Fullname;
        Dateofbirth = s.Dateofbirth;
        Address = s.Address;
    }

    ~Staff() {}

    friend istream &operator>>(istream &in, Staff &st)
    {
        in.ignore();
        getline(in, st.StaffID);
        in.ignore();
        getline(in, st.Fullname);
        in.ignore();
        getline(in, st.Dateofbirth);
        in.ignore();
        getline(in, st.Address);
        return in;
    }
    friend ostream &operator<<(ostream &out, Staff st)
    {
        out << "\nID: " << st.StaffID;
        out << "\nFull name: " << st.Fullname;
        out << "\nDate: " << st.Dateofbirth;
        out << "\nAddress: " << st.Address;
        return out;
    }
};

class ProductionStaff : public Staff
{

private:
    int NumberofProducts;

public:
    void setNUMBEROFPRODUCTS(int s) { s = NumberofProducts; }
    int getNUMBEROFPRODUCTS() { return NumberofProducts; }
    ProductionStaff(string _StaffID = "0", string _Fullname = "fullname", string _Dateofbirth = "0", string _Address = "address", int _NumberofProducts = 0)
        : Staff(_StaffID, _Fullname, _Dateofbirth, _Address)
    {
        NumberofProducts = _NumberofProducts;
    }

    ProductionStaff(const ProductionStaff &ps) : Staff(ps)
    {
        NumberofProducts = ps.NumberofProducts;
    }

    ~ProductionStaff() {}

    friend istream &operator>>(istream &in, ProductionStaff &ps)
    {
        string StaffID, FullName, Dateofbirth, Address;
        int NumberofProducts;

        in.ignore();
        cout << endl;
        getline(in, StaffID);
        getline(in, FullName);
        getline(in, Dateofbirth);
        getline(in, Address);
        in >> NumberofProducts;

        ps = ProductionStaff(StaffID, FullName, Dateofbirth, Address, NumberofProducts);

        return in;
    }
    friend ostream &operator<<(ostream &out, ProductionStaff ps)
    {
        out << "\nID: " << ps.getSTAFFID();
        out << "\nFull name: " << ps.getFULLNAME();
        out << "\nDate: " << ps.getDATEOFBIRTH();
        out << "\nAddress: " << ps.getADDRESS();
        out << "\nThe number of products are: " << ps.NumberofProducts;
        return out;
    }
    int Caculatesalary()
    {
        return NumberofProducts * 20000;
    }
};

class NormalStaff : public Staff
{

private:
    int Numberofdays;

public:
    void setNUMBEROFDAYS(int s) { s = Numberofdays; }
    int getNUMBEROFDAYS() { return Numberofdays; }
    NormalStaff(string _StaffID = "0", string _Fullname = "fullname", string _Dateofbirth = "0", string _Address = "address", int _Numberofdays = 0)
        : Staff(_StaffID, _Fullname, _Dateofbirth, _Address)
    {
        Numberofdays = _Numberofdays;
    }

    NormalStaff(const NormalStaff &ns) : Staff(ns)
    {
        Numberofdays = ns.Numberofdays;
    }

    ~NormalStaff() {}

    friend istream &operator>>(istream &in, NormalStaff &ns)
    {
        string StaffID, FullName, Dateofbirth, Address;
        int Numberofdays;

        in.ignore();
        cout << endl;
        getline(in, StaffID);
        getline(in, FullName);
        getline(in, Dateofbirth);
        getline(in, Address);
        in >> Numberofdays;

        ns = NormalStaff(StaffID, FullName, Dateofbirth, Address, Numberofdays);

        return in;
    }
    friend ostream &operator<<(ostream &out, NormalStaff ns)
    {
        out << "\nID: " << ns.getSTAFFID();
        out << "\nFull name: " << ns.getFULLNAME();
        out << "\nDate: " << ns.getDATEOFBIRTH();
        out << "\nAddress: " << ns.getADDRESS();
        out << "\nThe number of days are: " << ns.Numberofdays;
        return out;
    }
    int Caculatesalary()
    {
        return Numberofdays * 45000;
    }
};

class ManagementStaff : public Staff
{

private:
    int Wagecoefficient;

public:
    void setWAGECOEFFICIENT(int s) { s = Wagecoefficient; }
    int getWAGECOEFFICIENT() { return Wagecoefficient; }
    ManagementStaff(string _StaffID = "0", string _Fullname = "fullname", string _Dateofbirth = "0", string _Address = "address", int _Wagecoefficient = 0)
        : Staff(_StaffID, _Fullname, _Dateofbirth, _Address)
    {
        Wagecoefficient = _Wagecoefficient;
    }

    ManagementStaff(const ManagementStaff &ms) : Staff(ms)
    {
        Wagecoefficient = ms.Wagecoefficient;
    }

    ~ManagementStaff() {}
    friend istream &operator>>(istream &in, ManagementStaff &ms)
    {
        string StaffID, FullName, Dateofbirth, Address;
        int Wagecoefficient;

        in.ignore();
        cout << endl;
        getline(in, StaffID);
        getline(in, FullName);
        getline(in, Dateofbirth);
        getline(in, Address);
        in >> Wagecoefficient;

        ms = ManagementStaff(StaffID, FullName, Dateofbirth, Address, Wagecoefficient);

        return in;
    }
    friend ostream &operator<<(ostream &out, ManagementStaff ms)
    {
        out << "\nID: " << ms.getSTAFFID();
        out << "\nFull name: " << ms.getFULLNAME();
        out << "\nDate: " << ms.getDATEOFBIRTH();
        out << "\nAddress: " << ms.getADDRESS();
        out << "\nThe number of days are: " << ms.Wagecoefficient;
        return out;
    }
    int Caculatesalary()
    {
        if (Wagecoefficient >= 24)
        {
            return Wagecoefficient * 60000 + 1000000;
        }
        else
        {
            return Wagecoefficient * 60000;
        }
    }
};

class Company : public ProductionStaff, public NormalStaff, public ManagementStaff
{

public:
    void ImportListOfStaff(ProductionStaff x[], int n, NormalStaff y[], int m, ManagementStaff z[], int c)
    {

        for (int i = 0; i < n; i++)
        {
            cin >> x[i];
        }

        for (int i = 0; i < m; i++)
        {
            cin >> y[i];
        }

        for (int i = 0; i < c; i++)
        {
            cin >> z[i];
        }
    }

    void ExportListOfStaff(ProductionStaff x[], int n, NormalStaff y[], int m, ManagementStaff z[], int c)
    {
        std::cout.imbue(std::locale("")); // them dau phay dinh dang money
        cout << "\n 1.The list of Production Staffs";
        if (n == 0)
            cout << "\nNO DATA\n";
        for (int i = 0; i < n; i++)
        {
            cout << "\n\t Staff " << i + 1;
            cout << x[i];
            cout << endl;
            if (x[i].getNUMBEROFPRODUCTS() >= 30)
            {
                cout << "Salary: " << x[i].Caculatesalary() << "VND" << endl;
                cout << "Bonus: " << 500000 << "VND" << endl;
                cout << "Total: " << x[i].Caculatesalary() + 500000 << "VND" << endl;
            }
            else
            {
                cout << "Salary: " << x[i].Caculatesalary() << "VND" << endl;
            }
        }

        cout << "\n 2.The list of Normal Staffs";
        if (m == 0)
            cout << "\nNO DATA\n";
        for (int i = 0; i < m; i++)
        {
            cout << "\n\t Staff " << i + 1;
            cout << y[i];
            cout << endl;
            if (y[i].getNUMBEROFDAYS() >= 24)
            {
                cout << "Salary: " << y[i].Caculatesalary() << "VND" << endl;
                cout << "Bonus: " << 750000 << "VND" << endl;
                cout << "Total: " << y[i].Caculatesalary() + 750000 << "VND" << endl;
            }
            else
            {
                cout << "Salary: " << y[i].Caculatesalary() << "VND" << endl;
            }
        }

        cout << "\n 3.The list of Management Staffs";
        if (c == 0)
            cout << "\nNO DATA\n";
        for (int i = 0; i < c; i++)
        {
            cout << "\n\t Staff " << i + 1;
            cout << z[i];
            cout << endl;
            if (z[i].getWAGECOEFFICIENT() >= 24)
            {
                cout << "Salary: " << z[i].Caculatesalary() << "VND" << endl;
                cout << "Bonus: " << 1000000 << "VND" << endl;
                cout << "Total: " << z[i].Caculatesalary() + 1000000 << "VND" << endl;
            }
            else
            {
                cout << "Salary: " << z[i].Caculatesalary() << "VND" << endl;
            }
        }
    }

    void TotalSalary(ProductionStaff x[], int n, NormalStaff y[], int m, ManagementStaff z[], int c)
    {

        int sum1 = 0;
        for (int i = 0; i < n; i++)
        {
            sum1 += x[i].Caculatesalary();
        }

        int sum2 = 0;
        for (int i = 0; i < m; i++)
        {
            sum2 += y[i].Caculatesalary();
        }

        int sum3 = 0;
        for (int i = 0; i < c; i++)
        {
            sum1 += z[i].Caculatesalary();
        }

        cout << "\n\n\t\tThe total salary of all staff is: " << sum1 + sum2 + sum3 << "VND";
    }

    void TheHighestSalary(ProductionStaff x[], int n, NormalStaff y[], int m, ManagementStaff z[], int c)
    {

        int max1 = x[0].Caculatesalary();
        int s1 = 0;
        for (int i = 0; i < n; i++)
        {
            if (max1 < x[i].Caculatesalary())
            {
                max1 = x[i].Caculatesalary();
                s1 = i;
            }
        }

        int max2 = y[0].Caculatesalary();
        int s2 = 0;
        for (int i = 0; i < m; i++)
        {
            if (max2 < y[i].Caculatesalary())
            {
                max2 = y[i].Caculatesalary();
                s2 = i;
            }
        }

        int max3 = z[0].Caculatesalary();
        int s3 = 0;
        for (int i = 0; i < c; i++)
        {
            if (max3 < z[i].Caculatesalary())
            {
                max3 = z[i].Caculatesalary();
                s3 = i;
            }
        }

        int _max = max1;
        int _smax = s1;
        if (_max < max2)
        {
            _max = max2;
            _smax = s2;
        }

        if (_max < max3)
        {
            _max = max3;
            _smax = s3;
        }
        cout << "\n\n\t\tThe highest salary in the company is: " << _max << "VND";
        for (int i = 0; i < n; i++)
        {
            if (x[i].Caculatesalary() == _max)
            {
                cout << " \n\n\t\tThe staff having this salary : ";
                cout << x[_smax];
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (y[i].Caculatesalary() == _max)
            {
                cout << " \n\nThe staff having this salary : ";
                cout << y[_smax];
            }
        }

        for (int i = 0; i < c; i++)
        {
            if (z[i].Caculatesalary() == _max)
            {
                cout << " \n\nThe staff having this salary : ";
                cout << z[_smax];
            }
        }
    }
};

int main()
{

    ProductionStaff listof_PStaff[100];
    int n;
    cin >> n;

    NormalStaff listof_NStaff[100];
    int m;
    cin >> m;

    ManagementStaff listof_MStaff[100];
    int c;
    cin >> c;

    Company ABC;
    ABC.ImportListOfStaff(listof_PStaff, n, listof_NStaff, m, listof_MStaff, c);
    ABC.ExportListOfStaff(listof_PStaff, n, listof_NStaff, m, listof_MStaff, c);
    ABC.TotalSalary(listof_PStaff, n, listof_NStaff, m, listof_MStaff, c);
    ABC.TheHighestSalary(listof_PStaff, n, listof_NStaff, m, listof_MStaff, c);
    return 0;
}