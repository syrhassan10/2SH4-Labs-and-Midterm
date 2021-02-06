/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author jianfeng
 */
public class Matrix {
	
	//comment
    
	private int[][]  matrixData;
	private int    rowsNum;	
	private int    colsNum;	
	
	public Matrix( int row, int col ) 
	{   
		/*
		* constructs a row-by-col matrix with
		* all elements equal to 0; if row <= 0, the number of rows of the matrix is set to
		* 3; likewise, if col <= 0 the number of columns of the matrix is set to 3.		
		*/
		if (row<=0 &&col<=0) {
		
			rowsNum = 3;
			colsNum = 3;

		}
		else if(row<=0) {
			rowsNum = 3;
			colsNum= col;
		}
		else if(col<=0) {
			rowsNum= row;
			colsNum = 3;
		}
		else {
			rowsNum = row;
			colsNum = col;
		}
		matrixData = new int[rowsNum][colsNum];
	}

	public Matrix( int[][] table) 
	{	

		/*
		* constructs a matrix out of the two dimensional array table, with the same number of rows, columns, and the same
		* element in each position as array table.
		*/ 
		rowsNum=table.length;
		colsNum =table[0].length;
		matrixData = new int[rowsNum][colsNum];
		for(int i =0;i<rowsNum;i++) {
				matrixData[i] = table[i];
		}
		//System.out.println(matrixData);
	}
	
	public int getElement(int i, int j) throws IndexOutOfBoundsException
	{ 	
		/*
		* returns the element on row i and column j of this matrix; 
		* it throws an exception (IndexOutOfBoundsException) if any of indexes i and j is not in the required range 
		* (rows and columns indexing starts with 0)
		*  the detail message of the exception should read: "Invalid indexes".
		*/
	
		try {
			
			return matrixData[i][j];
		}catch(Exception e) {
			throw new IndexOutOfBoundsException("Invalid indexes.");
			
		}
		
		
		
		
		
	}
        
    public boolean setElement(int x, int i, int j)throws IndexOutOfBoundsException{ 
            
        /* the detail message of the exception should read: "Invalid indexes" */
    	try {
			this.matrixData[i][j] =x;
			return true;
		}catch(Exception IndexOutOfBoundsException) {
			System.out.println("Invalid indices");
			return false;
		}
    	
    } 

    public Matrix copy(){ 
        
    	/* fix the code and write your implementation below */
		Matrix copy = new Matrix (rowsNum,colsNum);
		
		for (int i=0;i<rowsNum;i++) {
			for(int j =0;j<colsNum;j++) {
				copy.setElement(getElement(i,j), i, j);
			}
		}
		
		
        return  copy; 
    }    
                
	public void addTo( Matrix m ) throws ArithmeticException
	{
		
		/* the detail message of the exception should read: "Invalid operation". */
		int size_r = 0;
		int size_c = 0;
		size_r = m.getsizeofrows();
		size_c = m.getsizeofcols();
		if (size_r == rowsNum && size_c==colsNum) {
			for (int i=0;i<rowsNum;i++) {
				for(int j =0;j<colsNum;j++) {
					matrixData[i][j]+=m.getElement(i, j);
				}
			}
		}else{
			//System.out.println(e);
			throw new ArithmeticException("Invalid operation");
		}
		
	
	}
	
    public Matrix subMatrix(int i, int j) throws ArithmeticException{ 
        
		/* The exception detail message should read: "Submatrix not defined"*/
    	
    	/* fix the code and write your implementation below */
		Matrix subM = new Matrix (i+1,j+1);
		
		try {
			for (int k =0;k<i+1;k++) {
				for(int g=0;g<j+1;g++) {
					subM.setElement(matrixData[k][g], k, g);
				}
			}
			 return  subM; 
		}catch(Exception e) {
			throw new ArithmeticException("Submatrix not defined");
		}
		
		
       
        
    }
        
    public int getsizeofrows(){ 
           
		/* update below return */
    	if(rowsNum>=0) {
    		return rowsNum;
    	}
    	
		return -1;
    }
        
    public int getsizeofcols(){
		
		/* update below return */
    	if (colsNum>=0) {
    		return colsNum;
    	}
    	
    	return -1; 
    }
        
    public boolean isUpperTr(){
            
		/* write your implementation here and update return accordingly */
    	boolean check = false;
    	for (int x =0;x<colsNum;x++) {//columns
    		for (int y =x+1;y<rowsNum;y++) {//rows
    			if(matrixData[y][x]!=0) {
    				return false;
    			}
    		}
    		
    	}
    	return true; 
	}
        
    public static Matrix sum(Matrix[] matArray) throws ArithmeticException{
            
        int r_size = 0;
        int c_size = 0;
        r_size = matArray[0].getsizeofrows();
        c_size = matArray[0].getsizeofcols();
        Matrix superMatrix = new Matrix (r_size,c_size); 
            
    	try {
			 for (int i =0;i<matArray.length;i++) {
				superMatrix.addTo(matArray[i]);
			 }
			 return superMatrix; 
		}catch(ArithmeticException e) {
			System.out.println("sum is shit");
			throw new ArithmeticException("Invalid operation");
		}
       
    }
        
	public String toString(  )
	{
		String output = new String(); 
		for(int i[]: matrixData){
		    
		    for(int j: i){
		    	output +=j+" ";
		        //System.out.print(j);
		    }
		    output += "\n";
		    
		}
		return output;
	}
    
}