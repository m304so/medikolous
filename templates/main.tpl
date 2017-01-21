<!DOCTYPE html>
<html lang="en">
{include file="b-header.tpl"}

	{if $tpl}
		{foreach from=$tpl item=page}
			{include file=$page}
		{/foreach}
	{/if}

{include file="b-footer.tpl"}
</html>
<script type="text/javascript" src="../js/scripts.js"></script>