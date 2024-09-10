void solveTowersOfHanoi(const int& count, const char& src, const char& dest, const char& spare)
{
    if (count == 1)
    {
        std::cout << "Move the top disk from pole " << src << " to pole " << dest << '\n';
    }
    else
    {
        solveTowersOfHanoi(count-1, src, spare, dest);
        solveTowersOfHanoi(1, src, dest, spare);
        solveTowersOfHanoi(count-1, spare, dest, src);
    }
}