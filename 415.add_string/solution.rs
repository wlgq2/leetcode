impl Solution 
{
    pub fn add_strings(mut num1: String,mut num2: String) -> String 
    {
    	let mut temp = String::new();
    	let mut v:u8 = 0;
    	loop
    	{
    		let v1 = num1.pop();
    		let v2 = num2.pop();
    		if v1 == None && v2 == None && v ==0
    		{
    			break;
    		}
    		if let Some(v1) = v1
    		{
    			v += v1 as u8 - 48;
    		}
    		if let Some(v2) = v2
    		{
    			v+= v2 as u8 - 48;
    		}
    		let v3:u8 = v%10;
    		temp.push_str(&(v3.to_string())); 
    		v /= 10;
    	}
    	let mut rst = String::new();
    	loop
        {
        	if let Some(ch) = temp.pop()
        	{
        		rst.push(ch);
        	}
        	else 
        	{
        		break;
        	}
    	}
        return rst;
    }
}
