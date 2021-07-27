//
//  main.cpp
//  35_Non-type_Parameters
//
//  Created by 세광 on 2021/07/27.
//

#include <iostream>

using namespace std;

// 템플릿에 파라미터의 타입만 넣을 수 있는 것이 아닌 정수값도 넣을 수 있음 & 정수값 자체도 타입의 일부가 됨
// 비타입 파라미터에 들어온 인수는 변수가 아닌 일종의 상수 -> class의 멤버를 배열로 초기화할 때에도 사용할 수 있음
template<typename T, int n>
class Vector {
public:
    T GetComp(int i) const { return comp[i]; }
    void SetComp(int i, T val) { comp[i] = val; }
    Vector operator+(const Vector &rhs) const {
        Vector res;
        for (int i = 0; i < n; i++) {
            res.comp[i] = this->comp[i] + rhs.comp[i];
            // res.SetComp(i, this->GetComp(i), rhs.GetComp(i));
        }
        return res;
    }
    
private:
    T comp[n]; // 배열이 멤버 변수일 경우 항상 깊은 복사가 일어남
};

int main() {
    Vector<float, 3> v1, v2;
    
    v1.SetComp(0, 2);
    v1.SetComp(1, 3);
    v1.SetComp(2, 4);
    
    v2.SetComp(0, 5);
    v2.SetComp(1, 6);
    v2.SetComp(2, 7);
    
    Vector<float, 3> v3 = v1 + v2;
    
    cout << v3.GetComp(0) << ", " << v3.GetComp(1) << ", " << v3.GetComp(2) << endl;
}
