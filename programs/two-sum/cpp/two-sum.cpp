std::vector<int> twoSum(std::vector<int>& nums, int target)
{
    std::vector<int> indices;
    for (int i = 0; i < nums.size(); ++i)
    {
        for (int j = i+1; j < nums.size(); ++j)
        {
            if (nums[i]+nums[j] == target)
            {
                out.push_back(i);
                out.push_back(j);

                return indices;
            }
        }
    }

    return indices;
}