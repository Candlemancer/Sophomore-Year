<!DOCTYPE html> 
<html lang="en">
	<head>
		<meta charset="utf-8">
        <title>Forms</title>	
		<link href="styleForms.css" rel="stylesheet" type="text/css" />		
    </head>
    <body>

		<h1>Control Structures</h1>

		<h1>Getting Input With Forms</h1>		

		<?php 
			//Variable Initializations
			$message = "Happy Birthday";
			$text_input = "";
			$temperature_result = "";

			//First Button Clicked
			if (isset($_POST["submit"])){
				if( isset($_POST["textarea"]) ) { $message = htmlentities($_POST["textarea"]); }
				if( isset($_POST["text"]) )		{ $text_input = htmlentities($_POST["text"]); }				
			}

			//Second Button Clicked
			if (isset($_POST["clear"])){
				if( isset($_POST["textarea"]) )	{ $message = ""; }
				if( isset($_POST["text"]) ) 	{ $text_input = ""; }	
			}				

			//Convert Button Clicked
			if (isset($_POST["convert"])){
				$temperature_result = tempConvert($_POST["fahrenheit"]);
			}		
		?>

		<form action ="forms.php" method="post">
			<div>

				<!--Temperature Conversion-->
				<fieldset>
					<legend>Convert Temperatures</legend>

					<label class="TemperatureLabel">Fahrenheit Temp</label>
					<input name="fahrenheit" type="text" value=""/>
					<br/>
					<label class="TemperatureLabel">Celsius Temp</label>
					<input name="celsius" type="text" value= "<?php printf("%.1f", $temperature_result); ?>" />
					
					<input name="convert" type="submit" value="Convert"/>
					
					<p>Input a value in the Fahrenhiet field and click "Convert".</p>
				</fieldset>

				<!--Text Box-->
				<label>Text: <input name="text" type = "text" value = <?php echo $text_input ?>></label>
				
				<!--Checkboxes-->
				<p>
				<label class = "CheckLabel" for="Chocolate" >Chocolate: </label> 
				<input 	id= "Chocolate" 
						name="checkbox[]" 
						type = "checkbox" 
						value = "chocolate" 
						<?php 	if(isset($_POST["checkbox"]) && isset($_POST["submit"])) {
									if(in_array("chocolate", $_POST["checkbox"])) { echo "checked"; }
								}
						?> 
				/>
				<br/>
				
				<label class = "CheckLabel" for="Strawberry" >Strawberry: </label> 
				<input 	id= "Strawberry" 
						name="checkbox[]" 
						type = "checkbox" 
						value = "strawberry"
						<?php 	if(isset($_POST["checkbox"]) && isset($_POST["submit"])) {
									if(in_array("strawberry", $_POST["checkbox"]))	{ echo "checked"; }
								}
						?>	
				/>
				<br/>

				<label class = "CheckLabel" for="Vanilla" >Vanilla: </label> 
				<input 	id= "Vanilla" 
						name="checkbox[]" 
						type = "checkbox" 
						value = "vanilla" 								
						<?php 	if(isset($_POST["checkbox"]) && isset($_POST["submit"]) ) {
									if(in_array("vanilla", $_POST["checkbox"]))	{ echo "checked"; }
								}
						?>	
				/>
				<br/>

				<label class = "CheckLabel" for="Mint" >Mint: </label> 
				<input 	id= "Mint" 
						name="checkbox[]" 
						type = "checkbox" 
						value = "mint" 								
						<?php 	if(isset($_POST["checkbox"]) && isset($_POST["submit"]) ) {
									if(in_array("mint", $_POST["checkbox"]) ) { echo "checked"; }
								}
						?>	
				/>
				</p>

				<!--Radio Buttons-->
				<legend>Ice Cream Flavors</legend>
				<fieldset>
				<label>Pickle: <input name="radio1" type = "radio" value = "pickle" checked /></label>
				<label>Tomato: <input name="radio2" type = "radio" value = "tomato" /></label>
				<label>Lettuce: <input name="radio3" type = "radio" value = "lettuce" /></label>
				<label>Onion: <input name="radio4" type = "radio" value = "onion" /></label>
				</fieldset>

				<!--Text Area-->
				<p> <textarea name="textarea"><?php echo $message ?></textarea> </p>

				<!--Dropdown Box-->
				<p>
				<select name="select">
					<option value= "Party">Party</option>
					<option value= "Cake">Cake</option>
					<option value= "Candles">Candles</option>
					<option value= "Ballons">Balloons</option>
				</select>
				</p>

				<!--Other Elements-->
				<p>
				<label>Hidden: 		<input name="hidden" type = "hidden" value = "pickle" /></label> 
				</p>

				<p>
				<label>Submit: 		<input name="submit" type = "submit" value = "Submit" /></label>
				<label>Clear: 		<input name="clear" type = "submit" value = "Clear" />	</label> 
				</p>

				<label>Password: 	<input name="password" type = "password" value = "" />	</label>
			</div>
		</form>
		<pre>
			<?php	
 				print_r($_POST);	
 				if(isset($_POST["text"])){
 					//print("<p>Text: ".$_POST["text"]."</p>");
 					$text_input = htmlentities($_POST["text"]);
 					echo "Cleaned Text:".$text_input;
 				}

				if(isset($_POST["checkbox"]))
					{
						print("<p>Checkbox: ". $_POST["checkbox"]. "</p>");
					}


				if(isset($_POST["radio1"]))
					{
						print("<p>Radio1: ". $_POST["radio1"]. "</p>");
					}
				if(isset($_POST["radio2"]))
					{
						print("<p>Radio2: ". $_POST["radio2"]. "</p>");
					}
				if(isset($_POST["radio3"]))
					{
						print("<p>Radio3: ". $_POST["radio3"]. "</p>");
					}
				if(isset($_POST["radio4"]))
					{
						print("<p>Radio4: ". $_POST["radio4"]. "</p>");
					}


				if(isset($_POST["hidden"]))
					{
						print("<p>Hidden: ". $_POST["hidden"]. "</p>");
					}
				if(isset($_POST["submit"]))
					{
						print("<p>Submit: ". $_POST["submit"]. "</p>");
					}
				if(isset($_POST["password"]))
					{
						//print("<p>Password: ". $_POST["password"]."</p>");	
						$password_input = htmlentities($_POST["password"]);
						echo "Cleaned Password: ".$password_input;	
					}

				function tempConvert($input) {
					return ($input - 32) / 1.8;
				}

				print_r($GLOBALS);
			?>

    </body>
</html>  
