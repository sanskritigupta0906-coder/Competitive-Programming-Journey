#include <bits/stdc++.h>
using namespace std;

// function jo clock ke 2 points ke beech ka min. segment return krega
vector<int> segment(int a, int b)
{

    vector<int> v;

    int diff = abs(a - b); // dono endpoints ke beech ka direct difference

    int x;
    
    // Agar difference 6 se bada hai to hume clock ka doosra (chhota) path lena padega.
    // Example: 12 aur 3 ya phir 3 aur 12 ke beech direct diff 9 hai, lekin minimum segment
    // actually 12 -> 1 -> 2 -> 3 wala hai jisme sirf 3 points aate hain.
    if (diff > 6)
    {
        for (int i = 1; i <= 12 - diff; i++) // 12 - diff se minimum segment ki length mil jaati hai
        {

            x = max(a, b) + i; // max endpoint se aage badhte hue segment ke points collect kar rahe hain

            if (x > 12)
                x %= 12; // 12 ke baad counting fir se 1 se start hogi

            v.push_back(x); // segment ke points vector me store kar liye
        }
    }

    else // Normal case: direct chhota segment hi minimum segment hai
    {

        for (int i = min(a, b) + 1; i <= max(a, b); i++)
            v.push_back(i);
    }

    return v;
} 
//end of segment function

int main()
{

    int t;
    cin >> t;
    //no. of test cases 

    while (t--)
    {

        int a, b, c, d;
        cin >> a >> b >> c >> d; // dono strings ke points input liye

        bool found = false; // abhi maan kar chal rahe hain ki strings intersect nahi karti


        vector<int> x = segment(a, b); // 1st string ka min. segment
        vector<int> y = segment(c, d); // 2nd string ka min. segment

        // Chhote segment par iterate karna convenient rahega

        if (x.size() < y.size())
        {
            for (auto i : x)
            {
                if ((i == c && i != d) || (i == d && i != c))
                {
                    found = true; //means strings are intersecting
                    break;
                }
                // Agar dusri string ka agar ek point
                // pehli string ke segment ke bahar jaata hai,
                // to strings intersect karengi.
            }
        }

        else
        {
            for (auto j : y)
            {
                if ((j == a && j != b) || (j == b && j != a))
                {
                    found = true;
                    break;
                }

                // Same logic, bas is baar dusre segment par iterate kar rahe hain
            }
        }

        if (found)
            cout << "YES" << endl;

        else
            cout << "NO" << endl;
    }
}
