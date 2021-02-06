/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


/**
 *
 * @author jianfeng
 */
public class UpperTriangularMatrix {
    private int n;
    private int[] array;
    
    public UpperTriangularMatrix(int n){
        if (n<=0) {
        	this.n = 1;
        }else {
        	this.n = n;
        }
        array = new int[n*(n+1)/2];
        
    }
    
    public UpperTriangularMatrix(Matrix upTriM) throws IllegalArgumentException{
    	this.n = upTriM.getsizeofrows();
        int size = n*(n+1)/2;
        array = new int[size];
        int temp =0;
        
    	if (upTriM.isUpperTr()==true) {
    		
    		for (int i =0;i<n;i++) {
    			for(int j =i;j<n;j++) {
    				array[temp]=upTriM.getElement(i, j);
    				temp++;
    				//System.out.println("processing");
    				//System.out.println(array[temp]);
    			}
    		}
    		
    	}else {
    		throw new IllegalArgumentException("Not an upper triangular Matrix");
    	}
        
    }    
        
    public int getDim(){
        
		
		/* write your implementation here and update return accordingly */
    	
        return this.n; 
    }
    
    public int getElement(int i, int j) throws IndexOutOfBoundsException{
		int ans = i*(2*n-i+1)/2+j-i;

 		/* write your implementation here and update return accordingly */
    	try {
    		return array[ans];
    	}catch(Exception e){
    		throw new IndexOutOfBoundsException("Invalid indexes");
    	}
      
    }
    
    public void setElement(int x, int i, int j) throws IndexOutOfBoundsException,IllegalArgumentException{
    	int ans = i*(2*n-i+1)/2+j-i;
    	try {
    		array[ans]= x;
    	}catch(Exception e){
    		throw new IndexOutOfBoundsException("Invalid indexes");
    	}
    }
    
    public Matrix fullMatrix(){

        Matrix full= new Matrix(n,n); 
		int temp =0;
		for (int i =0;i<n;i++) {
			for(int j =i;j<n;j++) {
				
				full.setElement(this.array[temp], i, j);
				temp++;
			}
		}
        return full; 
    
    }
    
   
      
    public String toString(){
       //Matrix full = new Matrix(n,n);
    	
       
       String output= "";
       int a[][] = new int[n][n];
       int temp =0;
       for (int i =0;i<n;i++) {
			for(int j =i;j<n;j++) {
				
				a[i][j]=this.array[temp];
				temp++;
			}
		}
       
       for(int i[]: a){
		    
		    for(int j: i){
		    	output +=j+" ";
		        //System.out.print(j);
		    }
		    output += "\n";
		    
		}
       
       return output;
    }
    
    public int getDet(){
    	int ans =1;
    	Matrix full = this.fullMatrix();
        for (int i =0;i<n;i++) {
        	for(int j =0;j<n;j++) {
        		if (i==j) {
        			ans *=full.getElement(i, j);
        		}
        	}
        }
       return ans; 
    }

    public double[] effSolve(double[] b) throws IllegalArgumentException{

        /* fix the following and write your implementation */
    	double[] sol = new double[n];

    	double last =0;
           if (this.getDet() == 0) {
        	   throw new IllegalArgumentException("The determinant of the matrix is 0");
           }
           if (b.length!=n) {
        	   throw new IllegalArgumentException("The dimension of the matrix is not defined for operation");
           }
          //back propogation since we know its upper triangular last element will always equal to b[n-1]/a[n-1][n-1]
          
        for (int i = n - 1; i >=0; i--) {
           last = 0;
           for (int j = i; j < n; j++) {
              last += this.fullMatrix().getElement(i, j)*sol[j];
           }
           sol[i] = (b[i] - last)/this.fullMatrix().getElement(i, i);
        }
        return sol;  
    }   
}