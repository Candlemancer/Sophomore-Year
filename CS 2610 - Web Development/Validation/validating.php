<!DOCTYPE html> 

<html lang="en">
	<head>
		<meta charset="utf-8">
        <title>Validating Input</title>	
		<link href="styleValidating.css" rel="stylesheet" type="text/css" />		
    </head>
    <body>
			
		<?php 
		$cel = "";
		$fah = ""; 
		$qty0 = "";
		$qty1 = "";
		$qty2 = "";
		$error0 = "";
		$error1 = "";
		$error2 = "";
		$totalMsg = "";
		$errorMsg = "";
		
		if(isset($_POST['total'])){
			$error = false;
			for ($i = 0; $i < count($_POST["apple"]); $i++) {
				if(ctype_digit($_POST["apple"][$i]) || $_POST["apple"][$i] == "") {

				}
				else {
					$error = true;
					$errorName = "error$i";
					if(is_numeric($_POST["apple"][$i])) {
						$$errorName = "We only sell apples in full bushels. Please enter a whole number."; 
					}
					else {
						$$errorName = "Must enter a number.";
					}
				}

			}

			if (!$error) {	
				$total = 0;

				for($i=0; $i<count($_POST['apple']); $i++) {
					$total += $_POST['apple'][$i];
					$qtyName = "qty$i";
					$$qtyName = htmlentities($_POST["apple"][$i]);
				}
				
				$plural = "";
				if($total>1) {
					$plural = "s";
				}
				$totalMsg = "You have ordered $total bushel$plural of apples";
			}
			else {
				for($i=0; $i<count($_POST['apple']); $i++) {
					if(ctype_digit($_POST["apple"][$i])) {
						$qtyName = "qty$i";
						$$qtyName = htmlentities($_POST["apple"][$i]);
					}
				}
			}
		}
		
		if(isset($_POST['convert'])){
			if (empty($_POST["fahTemp"])) {
				$errorMsg = "No temperature entered. Please Enter a temperature in ºF.";
			}
			else {
				$fah = htmlentities($_POST['fahTemp']);
				$cel = convertToCelsius($fah);				
			}
		}
		?>
		
		<h1>Validating Input</h1>		
		<form action="validating.php" method="post">
			<fieldset><legend>Convert Temperatures</legend>
				<div>
					<label for="fahTemp">Enter Fahrenheit Temperature</label>
					<input type="text" id="fahTemp" value="<?php echo $fah ?>" name="fahTemp" />
					<span><?php echo $errorMsg; ?></span>
				</div>
				
				<div>
					<label for="celTemp">Celsius Temperature</label>
					<input type="text" id="celTemp" name="celTemp" value="<?php printf("%.1f", $cel); ?>" />
					<span></span>
				</div>
				
				<p>Enter the temperature in Fahrenheit. Click the Convert button and the Celsius temperature will be displayed.</p>
				<input type="submit" value="Convert" name="convert" />
			</fieldset>
			
			<fieldset><legend>Ordering Apples</legend>
				<p>Please enter the number of bushel you would like for each variety of apple.</p>
				
				<div>
					<label for="red">Red Delicious</label>
					<input type="text" id="red" value="<?php echo $qty0 ?>" name="apple[]" />
					<span> <?php echo $error0; ?> </span>	
				</div>
				
				<div>
					<label for="gala">Gala</label>
					<input type="text" id="gala" value="<?php echo $qty1 ?>" name="apple[]" />
					<span> <?php echo $error1; ?> </span>
				</div>
				
				<div>
					<label for="fuji">Fuji</label>
					<input type="text" id="fuji" value="<?php echo $qty2 ?>" name="apple[]" />
					<span> <?php echo $error2; ?> </span>
				</div>
				
				<div>
					<input type="submit" value="Compute Total" name="total" />
				<?php echo "$totalMsg"; ?></div>
			</fieldset>
			
        </form>
		
		<pre>
		<?php
		print_r($_POST);
		?>
		</pre>
		
		<?php		
		function convertToCelsius($fahrenheit){
			return ($fahrenheit-32)/1.8;
		}
		?>

		<h1>The end</h1>
    </body>
</html>  
