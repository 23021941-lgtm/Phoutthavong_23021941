void merge ( int*a, int left, int mid, int right ){
		int *b,c;
		b= new int [ mid - left + 1 ]
		c= new int [ right - mid ] 
	for(int i = left; i <= right; i++){ 
		if ( i <=m ) b[i] = a[i]
		else ( [i-m-1] = a[i] )}
int i = j = k = 0;
while ( i < m-left+1 && j < right - mid ){
	if ( b[i] < c[j] ) a[k] = b[i++];
	else a[k] = c[j++];
	k++
}
While ( i < m - left + 1 ){
	a[k++] = b[i++];
}
While (j < right - Mid ) {
	a[k++] = c[j++];
}
}
