using Mile.Project.Helpers;
using System.Xml;

namespace Mile.Internal.RefreshPackageVersion
{
    internal class Program
    {
        private static string RepositoryRoot = GitRepository.GetRootPath();

        static void Main(string[] args)
        {
            string NuspecFilePath = string.Format(
                @"{0}\Mile.Internal.NuGet\Mile.Windows.Internal.nuspec",
                RepositoryRoot);

            string VersionTag = string.Empty;
            //string VersionTag = "-preview";

            string VersionString = string.Format(
                "1.0.{0}.0{1}",
                DateTime.Today.Subtract(DateTime.Parse("2016-06-26")).TotalDays,
                VersionTag);

            XmlDocument Document = new XmlDocument();
            Document.PreserveWhitespace = true;
            Document.Load(NuspecFilePath);

            XmlNode? PackageNode = Document["package"];
            if (PackageNode != null)
            {
                XmlNode? MetadataNode = PackageNode["metadata"];
                if (MetadataNode != null)
                {
                    XmlNode? VersionNode = MetadataNode["version"];
                    if (VersionNode != null)
                    {
                        VersionNode.InnerText = VersionString;
                    }
                }
            }

            Document.Save(NuspecFilePath);

            Console.WriteLine(
                "Mile.Internal.RefreshPackageVersion task has been completed.");
            Console.ReadKey();
        }
    }
}
