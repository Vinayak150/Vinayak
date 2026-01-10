class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        for (int candidate = 1; candidate <= n; candidate++) {
            bool trustssome = false;
            bool trustsall = true;

            for (auto& t : trust) {
                int a = t[0];
                int b = t[1];

                if (a == candidate) {
                    trustssome = true;
                    break;
                }
            }

            if (trustssome)
                continue;

            for (int person = 1; person <= n; person++) {

                if (person == candidate)
                    continue;

                bool foundtrust = false;

                for (auto& t : trust) {
                    if (t[0] == person && t[1] == candidate) {
                        foundtrust = true;
                        break;
                    }
                }

                if (!foundtrust) {
                    trustsall = false ;
                    break;
                }
            }
            if (trustsall)
                return candidate;
        }

        return -1;
    }
};