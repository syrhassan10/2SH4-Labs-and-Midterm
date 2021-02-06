
public class SLLSet {
    private int size;
    private SLLNode head;

    public SLLSet() {
      this.size =0;
      this.head  = new SLLNode(0,null);
    }

    public SLLSet(int[] sortedArray) {
    	size = sortedArray.length;
    	head = new SLLNode(sortedArray[0],null);
    	SLLNode current = head;
		for(int i =1;i<sortedArray.length;i++) {
			current.next = new SLLNode(sortedArray[i],null);
			current = current.next;
		}
		
		
    	
    	
    	
        
    }

    public int getSize() {
		
        return this.size;
    }

    public SLLSet copy() {
    	SLLSet copy = new SLLSet();
    	copy.head = new SLLNode(this.head.value,null);
    	copy.size = this.size;
    	
    	
    	SLLNode current = this.head;
    	current =current.next;
    	SLLNode copycurrent = copy.head;
    	
    	for(int i =1;i<copy.size;i++) {
    		copycurrent.next = new SLLNode(current.value,null);
    		copycurrent = copycurrent.next;
    		current = current.next;
    		
    	}
    	
    	
    	
    	
    	
        return copy;
    }

    public boolean isIn(int v) {
    	SLLNode current = head;
  
		while(current!=null) {
			if(current.value == v) {
				return true;
			}
			current = current.next;
		}

    	
        return false;
    }

    public void add(int v) {
    	SLLNode current = head;
    	int c =0;
    	 if (this.isIn(v)) {
    		 return;
    	 }
    	size+=1;
		while(current!=null) {
			if(current.value < v) {// Case #1: inserting after
				if(current.next == null) {
					SLLNode newNode = new SLLNode(v,head);
					
					current.next = newNode;
					current = current.next;
					
					current.next = null;
					return;
					
					
				}
				else if(v>current.next.value) {
			
						current = current.next;
						c++;
		
					
				}else {
					SLLNode newNode = new SLLNode(v,current.next);
					current.next = newNode;
				
					return;
				}
				
			}else { //Case #2: Changing the Header
				if(c==0) {
					SLLNode newNode = new SLLNode(v,head);
					head = newNode;
					return;
				}
			}
			
			//Case#3: chaning last node????? where next = null
		}
    }

    public void remove(int v) {
    	
    	SLLNode current = head;
    	SLLNode tempcurrent = head;
    	
    	 if (this.isIn(v)!=true) {
    		 return;
    	 }
    	size-=1;
    	int c =0;
    	while(current!=null) {
    		if(current.value == v) {
    			if (c==0) {
    				this.head = current.next;
    				return;
    			}else {
    				tempcurrent.next = current.next;
    				return;
    			}
    		}
    		else {
    			current = current.next;
    			if(c>0) {
    				tempcurrent = tempcurrent.next;
    			}
    			c++;
    			
    		}
    		
    	}
    }

    public SLLSet union(SLLSet s) {
        
    	 SLLSet uni = copy();
         for(SLLNode n = s.head; n != null; n=n.next) {
             uni.add(n.value);
         }
         return uni;
    }

    public SLLSet intersection(SLLSet s) {
        
    	SLLSet inter = new SLLSet();
        for(SLLNode n = s.head; n != null; n=n.next) {
            if(isIn(n.value))
                inter.add(n.value);
        }
        return inter;
    
    }

    public SLLSet difference(SLLSet s) {
    	 SLLSet diff = new SLLSet();
         for(SLLNode n = head; n != null; n=n.next) {
             if(!s.isIn(n.value))
                 diff.add(n.value);
         }
         return diff;

    }

    public static SLLSet union(SLLSet[] sArray) {
    	SLLSet uni = sArray[0].copy();
        for(int i = 1; i < sArray.length; i++) {
            uni = uni.union(sArray[i]);
        }
        return uni;
    }

    @Override
    public String toString() {
    	String temp ="";
    	SLLNode current = head;
    	int c  =0;
		while(c<size) {
			
			temp+=current.value;
			
			current = current.next;
			if(c==size-1) {
				break;
			}else {
				temp+=", ";
				c++;
			}
			
		}
        return temp;
    }
}
