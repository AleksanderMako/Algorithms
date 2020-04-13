class Solution(object):
    def subdomainVisits(self, cpdomains):
        """
        :type cpdomains: List[str]
        :rtype: List[str]
        """
        domainsMap={}
        result=[]
        for _,domain in enumerate(cpdomains):
            
            separate = domain.split(" ")
            
            count = int(separate[0])
            domains =separate[1].split(".")
            self.buildDomains(domains,domainsMap,count)
        
        for k,v in domainsMap.items():
            
            result.append(str(v) +" "+k)
        return result
            
    
    def buildDomains(self,domains,domainsMap,basecount):
        for idx,_ in enumerate(domains):
            key = ".".join(domains[idx:])
            if key in domainsMap:
                domainsMap[key]+=basecount
            else :
                domainsMap[key]=basecount

            