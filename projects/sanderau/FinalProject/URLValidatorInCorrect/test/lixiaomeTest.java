

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String schemes) {
      super(schemes);
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing
	   //String[] schemes = {"http","https"};
	   //UrlValidator urlValidator = new UrlValidator(schemes);
	   //System.out.print(urlValidator.isValid("http://tech.yahoo.com/rc/desktops/102;_ylt=Ao8yevQHlZ4On0O3ZJGXLEQFLZA5"));
 String[] schemes = {"http","file","https"};
	   
       UrlValidator urlValidator1 = new UrlValidator(schemes); //test with specific schemes
       UrlValidator urlValidator2 = new UrlValidator(null); //test with default schemes
       //UrlValidator urlValidator3 = new UrlValidator(UrlValidator.ALLOW_ALL_SCHEMES); //test with all schemes
       //The third one is not working
       
       System.out.print("Manual Tests Started............\n");
       
       System.out.print("Testing: http://good.com = true: " + urlValidator1.isValid("http://good.com") + "\n");
       System.out.print("Testing: https://0.0.0.0 = true: " + urlValidator1.isValid("https://0.0.0.0") + "\n");
       System.out.print("Testing: http://hostname/path = false: " + urlValidator1.isValid("http://hostname/path") + "\n");
       System.out.print("Testing: http://255.com:65535/test1/test1 = false: " + urlValidator1.isValid("http://255.com:65535/test1/test1") + "\n");
       System.out.print("Testing: file://hostname/path/to/file = true: " + urlValidator1.isValid("file://hostname/path/to/file") + "\n");
       System.out.print("Testing: ftp://bad.com = false: " + urlValidator1.isValid("ftp://bad.com") + "\n");
       
       System.out.print("Testing: ftp://good.com = true: " + urlValidator2.isValid("ftp://good.com") + "\n");
       System.out.print("Testing: http://255.com:65535/test1/test1 = true: " + urlValidator2.isValid("http://255.com:65535/test1/test1") + "\n");
       System.out.print("Testing: test://bad.com = false: " + urlValidator2.isValid("test://bad.com") + "\n");
       //System.out.print(urlValidator3.isValid("test://good.com") + "\n");      
       
       System.out.print("Manual Tests Finished............\n");
   }
   
   
   //public void testYourFirstPartition()//In the other function created by group members.
   //{
	 //You can use this function to implement your First Partition testing	   

   //}
   
   //public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   //}
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing
	   String[][] group_scheme = {
			{"http://","true"},
			{"ftp://","true"},
			{"https://","true"},
			{"HTTP://","false"},
			{"://","false"},
			{"","true"},
			{"http:","false"},
			{"http:/","false"},
			{"http/","false"}
		   };
	   int scheme_len = 9;
	   
	   String[][] group_authority = {
			{"good.com","true"},
			{"www.good.com","true"},
			{"good.edu","true"},
			{"www.good.com","true"},
			{"0.0.0.0","true"},
			{"255.255.255.255","true"},
			{"256.256.256.256","false"},
			{"0.0.0.0.0","false"},
			{"0.0.0","false"},
			{"","false"},
			{"bad","false"},
			{"bad.abc","false"},
			{".bad","false"}	   
		   };
	   int auth_len = 13;
	   
	   String[][] group_path = {
			{"/test1","true"},
			{"/123","true"}, 
			{"/$123","true"},
			{"/..","false"},
			{"/../","false"},
			{"","true"},
			{"/test1/test","true"},
			{"/test1//test","false"},
			{"/..//test","false"}
		   };
	   int path_len = 9;
	   
	   String[][] group_query = {
			{"?action=view","true"},
			{"?action=edit&mode=up","true"},			   
			{"","true"},   				   
		   };   
	   int query_len = 3;
	   
	   String[] schemes = {"file","http"};
	   UrlValidator vali_file = new UrlValidator(schemes);//validator with scheme - file
	   UrlValidator vali_null = new UrlValidator(null);//default validator
	   String[] test_url = {"","true"};
	   String[] temp1 = {"",""};
	   String[] temp2 = {"",""};
	   String[] temp3 = {"",""};
	   System.out.print("Unit Tests Started............\n");
	   
	   for(int index_scheme = 0; index_scheme < scheme_len;index_scheme++) {
		   test_url[0] += group_scheme[index_scheme][0];
		   if(group_scheme[index_scheme][1] == "false") test_url[1] = "false";
		   temp1[0] = test_url[0];
		   temp1[1] = test_url[1];
		   for(int index_auth = 0; index_auth < auth_len;index_auth++) {
			   test_url[0] += group_authority[index_auth][0];
			   if(group_authority[index_auth][1] == "false") test_url[1] = "false";
			   temp2[0] = test_url[0];
			   temp2[1] = test_url[1];
			   for(int index_path = 0; index_path < path_len;index_path++) {
				   test_url[0] += group_path[index_path][0];
				   if(group_path[index_path][1] == "false") test_url[1] = "false";
				   temp3[0] = test_url[0];
				   temp3[1] = test_url[1];
				   for(int index_query = 0; index_query < query_len;index_query++) {
					   test_url[0] += group_query[index_query][0];
					   if(group_query[index_query][1] == "false") test_url[1] = "false";
					   
					   System.out.print("Testing: " + test_url[0] + " => ");
					   System.out.print(vali_null.isValid(test_url[0]));
					   if(test_url[1] == "true" && vali_null.isValid(test_url[0]) == true) {
						   //System.out.print("\nPassed\n");
					   }
					   else if(test_url[1] == "false" && vali_null.isValid(test_url[0]) == false) {
						   //System.out.print("\nPassed\n");
					   }
					   else System.out.print("\nFailed\n");
					   test_url[0] = temp3[0];
					   test_url[1] = temp3[1];
				   }
				   test_url[0] = temp2[0];
				   test_url[1] = temp2[1];
			   }
			   test_url[0] = temp1[0];
			   test_url[1] = temp1[1];
		   }	   
		   test_url[0] = "";
		   test_url[1] = "true";
	   }
	   
	   System.out.print("Unit Tests Finished............\n");
	   
	   System.out.print("Fixed Tests Started............\n");
	   		System.out.print("Testing: file://good.com = true: " + vali_file.isValid("file://good.com") + "\n");
	   		System.out.print("Testing: file:///good = true: " + vali_file.isValid("file:///good") + "\n");
	   		System.out.print("Testing: file://good.com/file = true: " + vali_file.isValid("file://good.com/file") + "\n");
	   		
	   		System.out.print("Testing: http://bad/test = false: " + vali_file.isValid("http://bad/test = false") + "\n");
	   		System.out.print("Testing: http:///good = false: " + vali_file.isValid("http:///good = false") + "\n");
	   		
	   System.out.print("Fixed Tests Finished............\n");
   }
   
   
   public static void main(String[] argv) {
	   UrlValidatorTest fct = new UrlValidatorTest("url test");
	   //assertTrue(true);
	   fct.testManualTest();
	   fct.testIsValid();
   }


}
