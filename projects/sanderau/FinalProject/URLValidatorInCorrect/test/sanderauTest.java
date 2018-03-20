

import org.junit.rules.ErrorCollector;

import junit.framework.TestCase;
import urlvalidatorincorrect.UrlValidator;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {
	
	//my class of pairs to help testing schemes
	public class Pair
	{
		private final String scheme;
		private final boolean key;
		
		public Pair(String aScheme, boolean aKey)
		{
			scheme = aScheme;
			key = aKey;
		}
		
		public boolean getKey() {return key; }
		public String getScheme() {return scheme;}
	}
	
	public boolean loud = true;
	
	//Before
	public void setUp() throws Exception {
		
	}
	 
	//After
	public void tearDown() throws Exception {
		
	}
	
	public void testAdd() {
		System.out.println("Hello world!");
	}


   public UrlValidatorTest(String testName) {
      super(testName);
   }

   
   /*
   public void testManualTest()
   {
      //You can use this function to implement your manual testing
	   
   }
   */
 
   
   public void testSchemes() //first input partition test
   {
	   if(loud)
	   {
		   System.out.println("\n Testing schemes: ");
	   }	   
	 //You can use this function to implement your First Partition testing	   
	   ErrorCollector collector = new ErrorCollector();
	   String [] schemes = {"https://", "ftp://", "http://", "http"};
	   UrlValidator urlVal = new UrlValidator(schemes, 0);
	   for(int sIndex = 0; sIndex < testSchemes.length; sIndex++)
	   {
		   Pair test = testSchemes[sIndex];
		   boolean result = urlVal.isValid(test.getScheme());
		   System.out.print("Test #" + sIndex + ": Tested: " + test.getScheme() + ", Expected: " + test.getKey() +  ", Received: " + result + " status: ");
		   if(result == test.getKey())
		   {
			   System.out.println("passed.");
		   }
		   else 
		   {
			   System.out.println("failed.");
		   }
	   }
   }
   
   
   /*
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   
   */
   //You need to create more test cases for your Partitions if you need to 
  /* 
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
*/

   Pair [] testSchemes = {new Pair("http", true), 
				new Pair("ftp://", true),
				new Pair ("https://", true),
				new Pair ("hwp:", false),
				new Pair ("axf/", false),
				new Pair ("http", false),
				new Pair ("", true),
				new Pair ("http://", true),
				new Pair ("://", false),
				new Pair ("/", false)};


}
