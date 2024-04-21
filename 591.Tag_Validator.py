class Solution:
    def isValid(self, code: str) -> bool:
        if code[0] != '<' or code[-1] != '>':
            return False
        
        contains_Tag, tag_Stack = False, []  
        
        def isValid_CDATA(s: str) -> bool:
            return s.find('[CDATA[') == 0
        
        def isValid_TagName(tag_Name: str, isEndTag: bool) -> bool:
            nonlocal contains_Tag
            if not tag_Name or len(tag_Name) > 9:
                return False
            if any(not ch.isupper() for ch in tag_Name):
                return False
            if isEndTag:
                return tag_Stack and tag_Stack.pop() == tag_Name
            
            contains_Tag = True
            tag_Stack.append(tag_Name)
            return True
        
        i = 0
        while i < len(code):
            if not tag_Stack and contains_Tag:
                return False
                
            if code[i] == '<':
                if tag_Stack and code[i+1] == '!':
                    close_Index = code.find(']]>', i+2)
                    if close_Index == -1 or not isValid_CDATA(code[i+2:close_Index]):
                        return False
                elif code[i+1] == '/':
                    close_Index = code.find('>', i+2)
                    if close_Index == -1 or not isValid_TagName(code[i+2:close_Index], True):
                        return False
                else:
                    close_Index = code.find('>', i+1)
                    if close_Index == -1 or not isValid_TagName(code[i+1:close_Index], False):
                        return False
                i = close_Index
            i += 1
            
        return not tag_Stack and contains_Tag

if __name__ == '__main__':
    s = Solution()
    print(s.isValid("<DIV>This is the first line <![CDATA[<div>]]></DIV>"))
    print(s.isValid("<DIV>>> ![cdata[]] <![CDATA[<div>]>]]>]]>>]</DIV>"))
    print(s.isValid("<A> <B> </A> </B>"))