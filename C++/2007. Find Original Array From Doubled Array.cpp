
vector<int> findOriginalArray(vector<int> &changed)
{

    bool trigger[changed.size()] = {false};
    sort(changed.begin(), changed.end());
    reverse(changed.begin(), changed.end());
    for (int i = 0; i < changed.size(); i++)
    {
        for (int j = i + 1; j < changed.size(); j++)
        {
            if (changed[i] == 2 * changed[j] && trigger[j] == false)
            {
                cout << "c1" << changed[i] << " " << changed[j] << endl;
                trigger[i] = true;
                break;
            }

            if (changed[j] == 2 * changed[i] && trigger[j] == false)
            {
                cout << "c2" << changed[i] << " " << changed[j] << endl;

                trigger[j] = true;
                break;
            }
        }
    }

    for (int i = 0; i < changed.size(); i++)
    {
        cout << trigger[i] << " ";
    }
    cout << endl;
    return changed;
}
