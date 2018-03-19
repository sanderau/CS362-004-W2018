import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!

public class thunesTests extends TestCase {


   public thunesTests(String testName) {
      super(testName);
   }

   public void testManualTest()
   {
//You can use this function to implement your manual testing	   
	   
   }
   
   public void testYourFirstPartition()
   {
     //You can use this function to implement your First Partition testing
     //test comment	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }

    //test 1-character paths
    public void testPaths(){

        UrlValidator urlVal = new UrlValidator(null,null,UrlValidator.ALLOW_ALL_SCHEMES);
        String url;
        String validUrlStart = "http://www.google.com";
        //set of allowed first characters (chars 'K' and '3' are representatives
        //for all alphanumeric characters; see input partitioning)
        String firstCharsValid = "K3:@&?=+,.w!~*'$_;";
        String firstCharsInvalid = "^`\"";   

        //test valid paths
        for (int i = 0; i < firstCharsValid.length(); i++) {
            url = validUrlStart + '/' + firstCharsValid.charAt(i);
            System.out.println("Testing Valid url: "+url);
            assertTrue(urlVal.isValid(url));
        }
        //test invalid paths
        for (int i = 0; i < firstCharsInvalid.length(); i++) {
            url = validUrlStart + '/' + firstCharsInvalid.charAt(i);
            System.out.println("Testing Invalid url: "+url);
            assertFalse(urlVal.isValid(url));
        }
    }
    
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   public static void main(String[] argv) {

	   	thunesTests fct = new thunesTests("url test");
	   	fct.testPaths();
   }


}
