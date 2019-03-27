int binary(int array[], int n, int v)
{
    int left, right, middle;

    left = -1, right = n ;
 
    while (  left + 1 != right )
    {
        middle = (left + right) / 2;
        if (array[middle] >= v)
        {
            right = middle ;
        }
        else 
        {
            left = middle  ;
        }
    }
    if( right == n || array[right]!= v)
        return -1;
    return right;
}