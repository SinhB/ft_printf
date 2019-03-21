					 FT_PRINTF
					 
 					SYNOPSIS
					
	ft_printf format [arguments ...]
	
 					DESCRIPTION
					
	The ft_printf utility formats and prints its arguments, after the first,
	under control of the format.  The format is a character string which con-
	tains three types of objects: plain characters, which are simply copied
	to standard output, character escape sequences which are converted and
	copied to the standard output, and format specifications, each of which
	causes printing of the next successive argument.

	The arguments after the first are treated as strings if the corresponding
	format is either c, b or s; otherwise it is evaluated as a C constant,
	with the following extensions:

		o   A leading plus or minus sign is allowed.
		o   If the leading character is a single or double quote, the value
			is the character code of the next character.

					 CONVERSIONS

	Each format specification is introduced by the percent character (``%'').
	The remainder of the format specification includes, in the following
	order:

	Zero or more of the following flags:
	
					 # - + space 0

	Field Width:
		An optional digit string specifying a field width; if the output
		string has fewer bytes than the field width it will be blank-
		padded on the left (or right, if the left-adjustment indicator
		has been given) to make up the field width (note that a leading
		zero is a flag, but an embedded zero is part of a field width);

	Precision:
		An optional period, `.', followed by an optional digit string
		giving a precision which specifies the number of digits to appear
		after the decimal point, for f formats, or the maximum number of
		bytes to be printed from a string; if the digit string is
		missing, the precision is treated as zero;
	Format:
		A character which indicates the type of format to use :
				 sSpdDioOuUxXcCfbB % M
		The uppercase formats differ from their lowercase counterparts
		only in that the output of the former is entirely in uppercase.
		The floating-point format specifiers
					 fF
		may be prefixed by an L to request that additional
		precision be used, if available.

	%           Print a `%'; no argument is used.

	M           Print the man.

	A field width or precision may be `*' instead of digit string.  
	In this case an argument supplies the field width or precision.

					 COLORS

	Colors:
		ANSI codes are used to give some joy and pleasure when using the
		ft_printf function.
		It is written as follow
				 {color_name}
		and it can be written everywhere in the format string.
		Available colors :
		{black}
			 {red}
				 {green}
					 {yellow}
						 {blue}
							 {violet}
								 {cyan}
									 {white}
		 {bold} --> write the text in bold.
		 {underline} --> underline the text.
		 {reset} --> reset all to default.
